/**
*
* LEI - UAB
*
* @classroom Laboratório de Programação (turma 3)
* @brief restaurant table management
* @author Carlos Romão
* @module main.c
* @date 13/06/2023
*
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "output.h"

int main() 
{
    TABLE* tables = NULL;
    int numTables = 0;

    CUSTOMERGROUP* customerGroups = NULL;
    int numGroups = 0;

    // Read tables from file
    readTablesFromFile(DATABASE_TABLE, &tables, &numTables);

    // Read customer groups from file
    readCustomerGroupsFromFile(DATABASE_CUSTOMERS, &customerGroups, &numGroups);

    // Allocate tables to customer groups
    allocateTables(tables, numTables, customerGroups, numGroups);

    // Free dynamically allocated memory
    free(tables);
    //free(customerGroups);

    return 0;
}

