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
    printf("5. View all records\n");
    printf("0. Exit program\n"); 
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
        case 5:  
            displayAllRecordsMenu();
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
    int temp_input; 
    int8_t temperature;
    
    printf("\n=== Add New Temperature Record ===\n");
    
    printf("Enter year: ");
    if (scanf("%hu", &year) != 1) {
        printf("Invalid input for year!\n");
        while(getchar() != '\n'); 
        return;
    }
    if (year < 1900 || year > 2100) {
        printf("Year must be between 1900 and 2100!\n");
        return;
    }
    
    printf("Enter month (1-12): ");
    if (scanf("%hhu", &month) != 1) {
        printf("Invalid input for month!\n");
        while(getchar() != '\n');
        return;
    }
    if (month < 1 || month > 12) {
        printf("Month must be between 1 and 12!\n");
        return;
    }
    
    printf("Enter day (1-31): ");
    if (scanf("%hhu", &day) != 1) {
        printf("Invalid input for day!\n");
        while(getchar() != '\n');
        return;
    }
        
    if (month == 2) {
        int isLeapYear = 0;        
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            isLeapYear = 1;
        }
        
        int maxDays = isLeapYear ? 29 : 28;
        if (day < 1 || day > maxDays) {
            printf("February has only %d days in %d!\n", maxDays, year);
            return;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) {
            printf("This month has only 30 days!\n");
            return;
        }
    } else {
        if (day < 1 || day > 31) {
            printf("Invalid day for this month!\n");
            return;
        }
    }
    
    printf("Enter hours (0-23): ");
    if (scanf("%hhu", &hours) != 1) {
        printf("Invalid input for hours!\n");
        while(getchar() != '\n');
        return;
    }
    if (hours > 23) {
        printf("Hours must be between 0 and 23!\n");
        return;
    }
    
    printf("Enter minutes (0-59): ");
    if (scanf("%hhu", &minutes) != 1) {
        printf("Invalid input for minutes!\n");
        while(getchar() != '\n');
        return;
    }
    if (minutes > 59) {
        printf("Minutes must be between 0 and 59!\n");
        return;
    }
    
    printf("Enter temperature (-128 to 127): ");
    if (scanf("%d", &temp_input) != 1) { 
        printf("Invalid input for temperature!\n");
        while(getchar() != '\n');
        return;
    }
    if (temp_input < -128 || temp_input > 127) {
        printf("Temperature must be between -128 and 127°C!\n");
        return;
    }
    temperature = (int8_t)temp_input; 
    
    addRecord(year, month, day, hours, minutes, temperature);
    printf("Record added successfully!\n");
}

void displayRemoveRecordMenu() {
    size_t index;
    
    printf("\n=== Remove Temperature Record ===\n");
    
    
    printAllRecords();
    
    if (recordsCount == 0) {
        printf("No records to remove.\n");
        return;
    }
    
    printf("\nEnter record index to remove (0-%zu): ", recordsCount - 1);
    if (scanf("%zu", &index) != 1) {
        printf("Invalid input for index!\n");
        while(getchar() != '\n');
        return;
    }
    
    if (index >= recordsCount) {
        printf("Invalid index!\n");
        return;
    }
       
    printf("\nRemoving record:\n");
    printf("Index %zu: %04d-%02d-%02d %02d:%02d, Temperature: %d°C\n",
           index,
           sensorData[index].year,
           sensorData[index].month,
           sensorData[index].day,
           sensorData[index].hours,
           sensorData[index].minutes,
           sensorData[index].temperature);
    
    printf("Are you sure? (1 = Yes, 0 = No): ");
    int confirm;
    if (scanf("%d", &confirm) != 1 || (confirm != 0 && confirm != 1)) {
        printf("Invalid input!\n");
        while(getchar() != '\n');
        return;
    }
    
    if (confirm == 1) {
        removeRecord(index);
        printf("Record removed successfully!\n");
    } else {
        printf("Removal canceled.\n");
    }
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
    
    
    char *dot = strrchr(fileName, '.');
    if (dot == NULL || strcmp(dot, ".csv") != 0) {
        printf("Error: File must have .csv extension!\n");
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

void displayAllRecordsMenu() {
    printf("\n=== View All Records ===\n");
    printAllRecords();
}