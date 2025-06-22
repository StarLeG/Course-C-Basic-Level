#include "readFileToBuffer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FILE_OPEN_ERROR -1
#define INVALID_FORMAT -2
#define BUFFER_OVERFLOW -3
#define INVALID_EXTENSION -4

int readFileToBuffer(char *fileName, char *buffer)
{
    char *dot = strrchr(fileName, '.');
    if (dot == NULL || strcmp(dot, ".csv") != 0)
    {
        return INVALID_EXTENSION;
    }

    FILE *file = fopen(fileName, "r");
    if (!file)
    {
        return FILE_OPEN_ERROR;
    }

    char line[256];
    int line_number = 0;
    size_t buffer_offset = 0;
    size_t buffer_size = strlen(buffer);

    while (fgets(line, sizeof(line), file))
    {
        line_number++;

        int year, month, day, hour, minute, temperature;
        int parsed = sscanf(line, "%4d;%2d;%2d;%2d;%2d;%d",
                            &year, &month, &day, &hour, &minute, &temperature);

        if (parsed != 6)
        {
            // Неверный формат строки
            int needed = snprintf(buffer + buffer_offset, buffer_size - buffer_offset,
                                  "Line %d: invalid format\n", line_number);
            if (needed >= buffer_size - buffer_offset)
            {
                fclose(file);
                return BUFFER_OVERFLOW;
            }
            buffer_offset += needed;
            continue;
        }

        // Проверка допустимости значений
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 ||
            hour < 0 || hour > 23 || minute < 0 || minute > 59 ||
            temperature < -99 || temperature > 99)
        {
            int needed = snprintf(buffer + buffer_offset, buffer_size - buffer_offset,
                                  "Line %d: invalid values\n", line_number);
            if (needed >= buffer_size - buffer_offset)
            {
                fclose(file);
                return BUFFER_OVERFLOW;
            }
            buffer_offset += needed;
            continue;
        }

        // Форматирование правильной строки
        int needed = snprintf(buffer + buffer_offset, buffer_size - buffer_offset,
                              "%04d;%02d;%02d;%02d;%02d;%d\n",
                              year, month, day, hour, minute, temperature);
        if (needed >= buffer_size - buffer_offset)
        {
            fclose(file);
            return BUFFER_OVERFLOW;
        }
        buffer_offset += needed;
    }

    fclose(file);
    return SUCCESS;
}