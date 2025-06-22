// main.c
#include <stdio.h>
#include "climate_data.h"
#include <string.h>
#include <limits.h>
#include "readFileToBuffer.h"
#include <unistd.h>
#include <stdlib.h>
#include "menu.h"
#include "config.h"

int main(int argc, char *argv[])
{
    // Инициализация тестовых данных
    addRecord(2023, 1, 15, 12, 30, -5);
    addRecord(2023, 1, 15, 18, 45, -7);
    addRecord(2023, 2, 20, 10, 15, 10);
    addRecord(2023, 2, 21, 9, 0, 8);
    addRecord(2024, 2, 21, 9, 0, 8);
    addRecord(2017, 2, 21, 9, 0, 8);
    addRecord(2018, 2, 12, 9, 0, 8);
    addRecord(2022, 12, 31, 23, 59, -15);

    // Обработка аргументов командной строки
    if (argc > 1)
    {
        int result = 0;
        char fileName[255] = {'\0'};

        while ((result = getopt(argc, argv, "hf:m:")) != -1)
        {
            switch (result)
            {
            case 'h':
                FILE *file = fopen("help.txt", "r");
                if (file == NULL)
                {
                    return 1;
                }

                char buff[1024];
                while (fgets(buff, sizeof(buff), file))
                {
                    fputs(buff, stdout);
                }
                fclose(file);
                return 0;

            case 'f':
                strcpy(fileName, optarg);
                break;
            case 'm':
                int month = atoi(optarg);
                if (month < 1 || month > 12)
                {
                    printf("Invalid month! Month should be between 1 and 12.\n");
                    return 1;
                }
                printStatsForMonthAllYears(month);
                return 0;
            case '?':
                printf("Error found !\n");
                break;
            }
        }

        char buffer[SIZE] = {'\0'};
        result = readFileToBuffer(fileName, buffer);
    }

    // Основное интерактивное меню
    int choice;
    do
    {
        displayMainMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            while (getchar() != '\n')
                ; 
            continue;
        }
        
         while (getchar() != '\n')
            ; 

        handleUserChoice(choice);
    } while (choice != 0);

    return 0;
}