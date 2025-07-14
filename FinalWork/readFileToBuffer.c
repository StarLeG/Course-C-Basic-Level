/**
 * @file readFileToBuffer.c
 * @brief Реализация функций чтения данных о температуре из файла
 */

#include "readFileToBuffer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "climate_data.h"

/**
 * @brief Читает данные о температуре из CSV файла в буфер
 * @param fileName Имя файла для чтения * 
 * @return int Код статуса (SUCCESS или код ошибки)
 */
int readFileToBuffer(char *fileName)
{
    if (!fileName)
        return INVALID_PARAM;

    const char *dot = strrchr(fileName, '.');
    if (!dot || strcmp(dot, ".csv") != 0)
    {
        return INVALID_EXTENSION;
    }

    FILE *file = fopen(fileName, "r");
    if (!file)
        return FILE_OPEN_ERROR;

    char line[256];
    size_t linesRead = 0;

    printf("Loading data...\n");
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    while (fgets(line, sizeof(line), file))
    {
        linesRead++;
        
        if (linesRead % 50000 == 0)
        {
            long pos = ftell(file);
            printf("\rProgress: %ld%%", (pos * 100) / fileSize);
            fflush(stdout);
        }

        if (line[0] == '\n' || line[0] == '#')
            continue;
        
        int Y, M, D, H, m, T;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &H, &m, &T) != 6)
        {
            printf(RED_TEXT "Error in line %zu: invalid format\n" RESET_TEXT, linesRead);
            continue; 
        }

        // Проверка корректности значений
        if (Y < 1900 || Y > 2100 || M < 1 || M > 12 || D < 1 || D > 31 || 
            H > 23 || m > 59 || T < -99 || T > 99)
        {
            printf(RED_TEXT "Error in line %zu: invalid values\n" RESET_TEXT, linesRead);
            continue;
        }

        if (recordsCount >= MAX_RECORDS)
        {
            fclose(file);
            return BUFFER_OVERFLOW;
        }

        addRecord(Y, M, D, H, m, T);
    }

    fclose(file);
    printf(GREEN_TEXT "\nLoaded lines: %zu\n" RESET_TEXT, linesRead);
    return SUCCESS;
}