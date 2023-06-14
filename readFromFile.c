/**
*
* LEI - UAB
*
* @classroom Laboratório de Programação (turma 3)
* @brief restaurant table management
* @author Carlos Romão
* @module  readFromFile.c
* @date 13/06/2023
*
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "readFromFile.h"

// Function to read tables from file and populate the array of table structures
void readTablesFromFile(const char* fileName, TABLE** tables, int* numTables)
{
    FILE* file = fopen(fileName, "r"); // Open the file in read mode

    if (file == NULL)
    {
        printf("Failed to open file: %s\n", fileName);
        return;
    }

    // Count the number of lines/tables in the file
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
    }
    *numTables = count;

    // Allocate memory for the table array
    *tables = (TABLE*)malloc(*numTables * sizeof(TABLE));
    if (*tables == NULL)
    {
        printf("Memory allocation failed for table array.\n");
        fclose(file);
        return;
    }

    // Reset file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    // Read table data from the file
    for (int i = 0; i < *numTables; i++)
    {
        if (fscanf(file, "%d,%d,%d", &(*tables)[i].tableNumber, &(*tables)[i].seats, &(*tables)[i].occupancy) != 3)
        {
            printf("Error reading table data from file: %s\n", fileName);
            free(*tables); // Free the allocated memory
            fclose(file);
            return;
        }
    }

    fclose(file);
}

void readCustomerGroupsFromFile(const char* fileName, CUSTOMERGROUP** customerGroups, int* numGroups)
{
    FILE* file = fopen(fileName, "r"); // Open the file in read mode

    if (file == NULL)
    {
        printf("Failed to open file: %s\n", fileName);
        return;
    }

    // Count the number of lines/groups in the file
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
    }
    *numGroups = count;

    // Allocate memory for the customer group array
    *customerGroups = (CUSTOMERGROUP*)malloc(*numGroups * sizeof(CUSTOMERGROUP));
    if (*customerGroups == NULL)
    {
        printf("Memory allocation failed for customer group array.\n");
        fclose(file);
        return;
    }

    // Reset file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    // Read customer group data from the file
    for (int i = 0; i < *numGroups; i++)
    {
        // Read the line into a temporary buffer
        char fileLine[256];
        if (fgets(fileLine, sizeof(fileLine), file) == NULL)
        {
            printf("Error reading customer group data from file: %s\n", fileName);
            free(*customerGroups); // Free the allocated memory
            fclose(file);
            return;
        }

        // Remove the newline character from the input line
        fileLine[strcspn(fileLine, "\n")] = 0;

        // Parse the line to extract the group identifier and number of people
        if (sscanf(fileLine, "%c,%d", &(*customerGroups)[i].groupIdentifier, &(*customerGroups)[i].numPeople) != 2)
        {
            printf("Error reading customer group data from file: %s\n", fileName);
            free(*customerGroups); // Free the allocated memory
            fclose(file);
            return;
        }
    }

    fclose(file);
}




