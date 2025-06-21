#include "climate_data.h"
#include <stdio.h>
#include <limits.h>

TemperatureRecord tempRecords[MAX_RECORDS];
size_t recordsCount = 0;

void addRecord(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature)
{
    if (recordsCount < MAX_RECORDS)
    {
        tempRecords[recordsCount].year = year;
        tempRecords[recordsCount].month = month;
        tempRecords[recordsCount].day = day;
        tempRecords[recordsCount].hours = hours;
        tempRecords[recordsCount].minutes = minutes;
        tempRecords[recordsCount].temperature = temperature;
        recordsCount++;
    }
}

void removeRecord(size_t index)
{
    if (index >= recordsCount)
    {
        return;
    }

    for (size_t i = index; i < recordsCount - 1; i++)
    {
        tempRecords[i] = tempRecords[i + 1];
    }

    recordsCount--;
}

int findAndRemoveRecord(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hours, uint8_t minutes, int8_t temperature)
{
    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year &&
            tempRecords[i].month == month &&
            tempRecords[i].day == day &&
            tempRecords[i].hours == hours &&
            tempRecords[i].minutes == minutes &&
            tempRecords[i].temperature == temperature)
        {
            removeRecord(i);
            return 1;
        }
    }
    return 0;
}

float getAverageMonthlyTemp(uint16_t year, uint8_t month)
{
    int sum = 0;
    int count = 0;

    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year && tempRecords[i].month == month)
        {
            sum += tempRecords[i].temperature;
            count++;
        }
    }

    return count > 0 ? (float)sum / count : 0;
}

int8_t getMinMonthlyTemp(uint16_t year, uint8_t month)
{
    int8_t min = INT8_MAX;

    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year && tempRecords[i].month == month)
        {
            if (tempRecords[i].temperature < min)
            {
                min = tempRecords[i].temperature;
            }
        }
    }

    return min != INT8_MAX ? min : 0;
}

int8_t getMaxMonthlyTemp(uint16_t year, uint8_t month)
{
    int8_t max = INT8_MIN;

    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year && tempRecords[i].month == month)
        {
            if (tempRecords[i].temperature > max)
            {
                max = tempRecords[i].temperature;
            }
        }
    }

    return max != INT8_MIN ? max : 0;
}

float getAverageYearlyTemp(uint16_t year)
{
    int sum = 0;
    int count = 0;

    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year)
        {
            sum += tempRecords[i].temperature;
            count++;
        }
    }

    return count > 0 ? (float)sum / count : 0;
}

int8_t getMinYearlyTemp(uint16_t year)
{
    int8_t min = INT8_MAX;

    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year)
        {
            if (tempRecords[i].temperature < min)
            {
                min = tempRecords[i].temperature;
            }
        }
    }

    return min != INT8_MAX ? min : 0;
}

int8_t getMaxYearlyTemp(uint16_t year)
{
    int8_t max = INT8_MIN;

    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year)
        {
            if (tempRecords[i].temperature > max)
            {
                max = tempRecords[i].temperature;
            }
        }
    }

    return max != INT8_MIN ? max : 0;
}

size_t countMonthlyRecords(uint16_t year, uint8_t month)
{
    size_t count = 0;
    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].year == year && tempRecords[i].month == month)
        {
            count++;
        }
    }
    return count;
}

void printMonthlyStats(uint16_t year)
{
    for (uint8_t month = 1; month <= 12; month++)
    {
        printf("Month %02d:\n", month);
        printf("  Average: %.1f°C\n", getAverageMonthlyTemp(year, month));
        printf("  Min: %d°C\n", getMinMonthlyTemp(year, month));
        printf("  Max: %d°C\n", getMaxMonthlyTemp(year, month));
    }
}

void printYearlyStats(uint16_t year)
{
    printf("Year %d Statistics:\n", year);
    printf("  Average: %.1f°C\n", getAverageYearlyTemp(year));
    printf("  Min: %d°C\n", getMinYearlyTemp(year));
    printf("  Max: %d°C\n", getMaxYearlyTemp(year));
}

void printStatsForMonthAllYears(uint8_t month)
{
    if (month < 1 || month > 12)
    {
        printf("Invalid month! Month should be between 1 and 12.\n");
        return;
    }

    printf("Statistics for month %02d across all years:\n", month);

    uint16_t years[MAX_RECORDS];
    size_t yearsCount = 0;

    for (size_t i = 0; i < recordsCount; i++)
    {
        if (tempRecords[i].month == month)
        {

            int found = 0;
            for (size_t j = 0; j < yearsCount; j++)
            {
                if (years[j] == tempRecords[i].year)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                years[yearsCount++] = tempRecords[i].year;
            }
        }
    }

    for (size_t i = 0; i < yearsCount; i++)
    {
        printf("Year %d:\n", years[i]);
        printf("  Average: %.1f°C\n", getAverageMonthlyTemp(years[i], month));
        printf("  Min: %d°C\n", getMinMonthlyTemp(years[i], month));
        printf("  Max: %d°C\n", getMaxMonthlyTemp(years[i], month));
        printf("\n");
    }
}