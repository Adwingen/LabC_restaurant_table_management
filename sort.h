/**
*
* LEI - UAB
*
* @classroom Laboratório de Programação (turma 3)
* @brief restaurant table management
* @author Carlos Romão
* @module  sort.h
* @date 13/06/2023
*
*/

#include "readFromFile.h"
#include <stdio.h>
#include <stdlib.h>

// Function to sort the available tables by the number of seats
void sortTables(TABLE* tables, int numTables);

// Function to sort the customer groups by the number of people in descending order
void sortGroups(CUSTOMERGROUP* customerGroups, int numGroups);

// Function to sort the allocation results by group identifier
void sortAllocationResults(AllocationResult* allocationResults, int numGroups);