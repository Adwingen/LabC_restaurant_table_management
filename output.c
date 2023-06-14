/**
*
* LEI - UAB
*
* @classroom Laboratório de Programação (turma 3)
* @brief restaurant table management
* @author Carlos Romão
* @module  output.h
* @date 13/06/2023
*
*/

#include "output.h"


// Function to print the allocation results in the sorted order
void printAllocationResults(AllocationResult* allocationResults, int numGroups)
{
    for (int i = 0; i < numGroups; i++)
    {
        printf("Group %c - ", allocationResults[i].groupIdentifier);
        if (allocationResults[i].assignedTable != -1)
        {
            printf("table %d\n", allocationResults[i].assignedTable);
        }
        else
        {
            printf("wait\n");
        }
    }
}

// Function to allocate tables to customer groups
void allocateTables(TABLE* tables, int numTables, CUSTOMERGROUP* customerGroups, int numGroups)
{
    // Sort the available tables by the number of seats
    sortTables(tables, numTables);

    // Sort the customer groups by the number of people in descending order
    sortGroups(customerGroups, numGroups);

    // Allocate tables to customer groups and store the allocation results in an array
    AllocationResult* allocationResults = (AllocationResult*)malloc(numGroups * sizeof(AllocationResult));
    if (allocationResults == NULL)
    {
        printf("Memory allocation failed for allocation results.\n");
        return;
    }

    for (int i = 0; i < numGroups; i++)
    {
        int groupSize = customerGroups[i].numPeople;
        int assignedTable = -1;

        for (int j = 0; j < numTables; j++)
        {
            if (tables[j].seats >= groupSize && tables[j].occupancy == 0)
            {
                assignedTable = tables[j].tableNumber;
                tables[j].occupancy = groupSize;
                break;
            }
        }

        allocationResults[i].groupIdentifier = customerGroups[i].groupIdentifier;
        allocationResults[i].assignedTable = assignedTable;
    }

    // Sort the allocation results by group identifier
    sortAllocationResults(allocationResults, numGroups);

    // Print the allocation results in the sorted order
    printAllocationResults(allocationResults, numGroups);

    // Free dynamically allocated memory
    free(allocationResults);
}