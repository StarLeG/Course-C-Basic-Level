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


    fclose(file);
    return SUCCESS;
}