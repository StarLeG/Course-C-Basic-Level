#pragma once

#include <stdint.h>

#define MAX_RECORDS 1000

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temperature;
} TemperatureRecord;

extern TemperatureRecord tempRecords[MAX_RECORDS];
extern size_t recordsCount;

void addRecord(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature);
void removeRecord(size_t index);

size_t countMonthlyRecords(uint16_t year, uint8_t month);

void printMonthlyStats(uint16_t year);
void printYearlyStats(uint16_t year);
void printStatsForMonthAllYears(uint8_t month);

float getAverageMonthlyTemp(uint16_t year, uint8_t month);
int8_t getMinMonthlyTemp(uint16_t year, uint8_t month);
int8_t getMaxMonthlyTemp(uint16_t year, uint8_t month);

float getAverageYearlyTemp(uint16_t year);
int8_t getMinYearlyTemp(uint16_t year);
int8_t getMaxYearlyTemp(uint16_t year);

