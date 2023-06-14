/**
*
* LEI - UAB
*
* @classroom Laboratório de Programação (turma 3)
* @brief restaurant table management
* @author Carlos Romão
* @module  sort.c
* @date 13/06/2023
*
*/

#include "sort.h"

// Function to sort the available tables by the number of seats
void sortTables(TABLE* tables, int numTables)
{
    for (int i = 0; i < numTables - 1; i++)
    {
        for (int j = 0; j < numTables - i - 1; j++)
        {
            if (tables[j].seats > tables[j + 1].seats)
            {
                TABLE temp = tables[j];
                tables[j] = tables[j + 1];
                tables[j + 1] = temp;
            }
        }
    }
}

// Function to sort the customer groups by the number of people in descending order
void sortGroups(CUSTOMERGROUP* customerGroups, int numGroups)
{
    for (int i = 0; i < numGroups - 1; i++)
    {
        for (int j = 0; j < numGroups - i - 1; j++)
        {
            if (customerGroups[j].numPeople < customerGroups[j + 1].numPeople)
            {
                CUSTOMERGROUP temp = customerGroups[j];
                customerGroups[j] = customerGroups[j + 1];
                customerGroups[j + 1] = temp;
            }
        }
    }
}

// Function to sort the allocation results by group identifier
void sortAllocationResults(AllocationResult* allocationResults, int numGroups)
{
    for (int i = 0; i < numGroups - 1; i++)
    {
        for (int j = 0; j < numGroups - i - 1; j++)
        {
            if (allocationResults[j].groupIdentifier > allocationResults[j + 1].groupIdentifier)
            {
                AllocationResult temp = allocationResults[j];
                allocationResults[j] = allocationResults[j + 1];
                allocationResults[j + 1] = temp;
            }
        }
    }
}