/**
*
* LEI - UAB
*
* @classroom Laboratório de Programação (turma 3)
* @brief restaurant table management
* @author Carlos Romão
* @module  database.h
* @date 13/06/2023
*
*/


#define DATABASE_TABLE "tables.csv"
#define DATABASE_CUSTOMERS "customers.csv"

// Structure to hold table information
typedef struct 
{
    int tableNumber;
    int seats;
    int occupancy;
    
} TABLE;

// Structure to hold customer group information
typedef struct 
{
    char groupIdentifier;
    int numPeople;
} CUSTOMERGROUP;


// Structure to hold the allocation result
typedef struct 
{
    char groupIdentifier;
    int assignedTable;
} AllocationResult;
