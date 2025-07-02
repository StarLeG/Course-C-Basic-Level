
#pragma once

#include <stdint.h>

#define SIZE 1000000
#define MAX_RECORDS 900000

#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1B[32m"
#define RESET_TEXT "\x1B[0m"


typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temperature;
} TemperatureRecord;