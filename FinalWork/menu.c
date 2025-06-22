// menu.c
#include "menu.h"
#include "climate_data.h"
#include "readFileToBuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include "config.h"

void displayMainMenu() {
    printf("\n=== Temperature Statistics Program ===\n");
    printf("1. Add new temperature record\n");
    printf("2. Remove temperature record\n");
    printf("3. View statistics\n");
    printf("4. Load data from file\n");
    printf("0. Exit\n");
}

void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            displayAddRecordMenu();
            break;
        case 2:
            displayRemoveRecordMenu();
            break;
        case 3:
            displayStatsMenu();
            break;
        case 4:
            loadDataFromFile();
            break;
        case 0:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

void displayAddRecordMenu() {
    uint16_t year;
    uint8_t month, day, hours, minutes;
    int8_t temperature;
    
    printf("\n=== Add New Temperature Record ===\n");
    
    printf("Enter year: ");
    if (scanf("%hu", &year) != 1) {
        printf("Invalid input for year!\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    
    printf("Enter month (1-12): ");
    if (scanf("%hhu", &month) != 1) {
        printf("Invalid input for month!\n");
        while(getchar() != '\n');
        return;
    }
    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return;
    }
    
    printf("Enter day (1-31): ");
    if (scanf("%hhu", &day) != 1) {
        printf("Invalid input for day!\n");
        while(getchar() != '\n');
        return;
    }
    
    printf("Enter hours (0-23): ");
    if (scanf("%hhu", &hours) != 1) {
        printf("Invalid input for hours!\n");
        while(getchar() != '\n');
        return;
    }
    
    printf("Enter minutes (0-59): ");
    if (scanf("%hhu", &minutes) != 1) {
        printf("Invalid input for minutes!\n");
        while(getchar() != '\n');
        return;
    }
    
    printf("Enter temperature (-128 to 127): ");
    if (scanf("%hhd", &temperature) != 1) {
        printf("Invalid input for temperature!\n");
        while(getchar() != '\n');
        return;
    }
    
    addRecord(year, month, day, hours, minutes, temperature);
    printf("Record added successfully!\n");
}

void displayRemoveRecordMenu() {
    size_t index;
    
    printf("\n=== Remove Temperature Record ===\n");
    printf("Current records count: %zu\n", recordsCount);
    
    if (recordsCount == 0) {
        printf("No records to remove.\n");
        return;
    }
    
    printf("Enter record index to remove (0-%zu): ", recordsCount - 1);
    if (scanf("%zu", &index) != 1) {
        printf("Invalid input for index!\n");
        while(getchar() != '\n');
        return;
    }
    
    if (index >= recordsCount) {
        printf("Invalid index!\n");
        return;
    }
    
    removeRecord(index);
    printf("Record removed successfully!\n");
}

void displayStatsMenu() {
    int choice;
    uint16_t year;
    uint8_t month;
    
    printf("\n=== Statistics Menu ===\n");
    printf("1. Monthly statistics for a year\n");
    printf("2. Yearly statistics\n");
    printf("3. Statistics for a month across all years\n");
    printf("0. Back to main menu\n");
    
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input for choice!\n");
        while(getchar() != '\n');
        return;
    }
    
    switch (choice) {
        case 1:
            printf("Enter year: ");
            if (scanf("%hu", &year) != 1) {
                printf("Invalid input for year!\n");
                while(getchar() != '\n');
                return;
            }
            printf("\nMonthly Statistics for %d:\n", year);
            printMonthlyStats(year);
            break;
        case 2:
            printf("Enter year: ");
            if (scanf("%hu", &year) != 1) {
                printf("Invalid input for year!\n");
                while(getchar() != '\n');
                return;
            }
            printf("\nYearly Statistics for %d:\n", year);
            printYearlyStats(year);
            break;
        case 3:
            printf("Enter month (1-12): ");
            if (scanf("%hhu", &month) != 1) {
                printf("Invalid input for month!\n");
                while(getchar() != '\n');
                return;
            }
            if (month < 1 || month > 12) {
                printf("Invalid month!\n");
                return;
            }
            printStatsForMonthAllYears(month);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void loadDataFromFile() {
    char fileName[256];
    
    printf("\n=== Load Data from File ===\n");
    printf("Enter file name: ");
    if (scanf("%255s", fileName) != 1) {
        printf("Invalid input for file name!\n");
        while(getchar() != '\n');
        return;
    }
    
    char buffer[SIZE] = {'\0'};
    int result = readFileToBuffer(fileName, buffer);
    
    if (result == 0) {
        printf("Data loaded successfully from %s\n", fileName);
    } else {
        printf("Error loading data from file. Error code: %d\n", result);
    }
}