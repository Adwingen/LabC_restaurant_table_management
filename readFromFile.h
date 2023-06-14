/**
*
* LEI - UAB
*
* @classroom Laborat�rio de Programa��o (turma 3)
* @brief restaurant table management
* @author Carlos Rom�o
* @module  readFromFile.h
* @date 13/06/2023
*
*/

#include "database.h"
#include <stdio.h>
#include <stdlib.h>

// Function to read tables from file and populate the array of table structures
void readTablesFromFile(const char* fileName, TABLE** tables, int* numTables);

// Function to read customer groups from file and populate the array of customer group structures
void readCustomerGroupsFromFile(const char* fileName, CUSTOMERGROUP** customerGroups, int* numGroups);

