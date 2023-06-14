/**
*
* LEI - UAB
*
* @classroom Laborat�rio de Programa��o (turma 3)
* @brief restaurant table management
* @author Carlos Rom�o
* @module  output.h
* @date 13/06/2023
*
*/

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

// Function to print the allocation results in the sorted order
void printAllocationResults(AllocationResult* allocationResults, int numGroups);

// Function to allocate tables to customer groups
void allocateTables(TABLE* tables, int numTables, CUSTOMERGROUP* customerGroups, int numGroups);