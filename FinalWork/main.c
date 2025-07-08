/**
 * @mainpage Temperature Statistics Program
 * @brief Итоговая работа по курсу «Программирование на языке С (базовый уровень)»
 * @author Старинский Олег Григорьевич
 * @date 2025
 * 
 * @section intro_sec Введение
 * Консольное приложение "Temperature Statistics", которое осуществляет считывание текстового файла csv,
 * состоящего из строк следующего формата:
 * YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE
 * dddd;mm;dd;hh;mm;temperature
 * dddd - год 4 цифры
 * mm - месяц 2 цифры
 * dd - день 2 цифры
 * hh - часы 2 цифры
 * mm - минуты 2 цифры
 *  temperature - целое число от -99 до 99
 */

#include <stdio.h>
#include "climate_data.h"
#include <string.h>
#include <limits.h>
#include "readFileToBuffer.h"
#include <unistd.h>
#include <stdlib.h>
#include "menu.h"
#include "config.h"

/**
 * @brief Главная функция программы
 * @param argc Количество аргументов
 * @param argv Массив аргументов
 * @return int Статус завершения программы
 */
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int result = 0;
        char fileName[255] = {'\0'};

        while ((result = getopt(argc, argv, "hf:m:d")) != -1)
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
            {
                strcpy(fileName, optarg);
                char buffer[SIZE];
                int loadStatus = readFileToBuffer(fileName, buffer);

                if (loadStatus != SUCCESS)
                {
                    printf("File upload error: ");
                    switch (loadStatus)
                    {
                    case FILE_OPEN_ERROR:
                        printf("File not found.\n");
                        break;
                    case INVALID_FORMAT:
                        printf("Invalid data format.\n");
                        break;
                    default:
                        printf("Unknown error.\n");
                    }
                    return 1;
                }
                printf("Data uploaded successfully!\n");
                break;
            }
            case 'm':
            {
                // char buffer[SIZE];
                // int loadStatus = readFileToBuffer("temperature_big.csv", buffer);

                // if (loadStatus != SUCCESS)
                // {
                //     printf(RED_TEXT "Error loading temperature_big.csv (code: %d)\n" RESET_TEXT, loadStatus);
                //     return 1;
                // }

                int month = atoi(optarg);
                if (month < 1 || month > 12)
                {
                    printf(RED_TEXT"Incorrect month! Acceptable values ​​are 1-12.\n"RESET_TEXT);
                    return 1;
                }

                //printf(GREEN_TEXT "Data loaded successfully!\n" RESET_TEXT);
                
                printStatsForMonthAllYears(month);
                return 0;
            }

            case '?':
                printf("Error found !\n");
                break;
            }
        }
    }

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

    freeTemperatureList();
    return 0;
}