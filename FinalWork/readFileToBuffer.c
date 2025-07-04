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

#define SUCCESS 0
#define FILE_OPEN_ERROR -1
#define INVALID_FORMAT -2
#define BUFFER_OVERFLOW -3
#define INVALID_EXTENSION -4
#define INVALID_PARAM -5

extern TemperatureRecord tmpSensorData;

/**
 * @brief Читает данные о температуре из CSV файла в буфер
 * @param fileName Имя файла для чтения
 * @param buffer Буфер для хранения содержимого файла
 * @return int Код статуса (SUCCESS или код ошибки)
 */

int readFileToBuffer(char *fileName, char *buffer) {
    if (!fileName || !buffer) return INVALID_PARAM;
    
    const char *dot = strrchr(fileName, '.');
    if (!dot || strcmp(dot, ".csv") != 0) {
        return INVALID_EXTENSION;
    }

    FILE *file = fopen(fileName, "r");
    if (!file) return FILE_OPEN_ERROR;

    char line[256];
    size_t linesRead = 0;
    
    while (fgets(line, sizeof(line), file)) {
        linesRead++;
        
        if (line[0] == '\n' || line[0] == '#') continue;
        
        int Y, M, D, H, m, T;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &H, &m, &T) != 6) {
            fprintf(stderr, "Invalid format at line %zu\n", linesRead);
            continue;
        }
        
        if (recordsCount >= MAX_RECORDS) {
            fclose(file);
            return BUFFER_OVERFLOW;
        }
        
        addRecord(Y, M, D, H, m, T);
    }

    fclose(file);
    return SUCCESS;
}