#include "climate_data.h"
#include <stdio.h>
#include <limits.h>

TemperatureRecord sensorData[MAX_RECORDS];
size_t recordsCount = 0;

void addRecord(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature)
{
    if (recordsCount < MAX_RECORDS)
    {
        sensorData[recordsCount].year = year;
        sensorData[recordsCount].month = month;
        sensorData[recordsCount].day = day;
        sensorData[recordsCount].hours = hours;
        sensorData[recordsCount].minutes = minutes;
        sensorData[recordsCount].temperature = temperature;
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
        sensorData[i] = sensorData[i + 1];
    }

    recordsCount--;
}

int findAndRemoveRecord(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hours, uint8_t minutes, int8_t temperature)
{
    for (size_t i = 0; i < recordsCount; i++)
    {
        if (sensorData[i].year == year &&
            sensorData[i].month == month &&
            sensorData[i].day == day &&
            sensorData[i].hours == hours &&
            sensorData[i].minutes == minutes &&
            sensorData[i].temperature == temperature)
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
        if (sensorData[i].year == year && sensorData[i].month == month)
        {
            sum += sensorData[i].temperature;
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
        if (sensorData[i].year == year && sensorData[i].month == month)
        {
            if (sensorData[i].temperature < min)
            {
                min = sensorData[i].temperature;
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
        if (sensorData[i].year == year && sensorData[i].month == month)
        {
            if (sensorData[i].temperature > max)
            {
                max = sensorData[i].temperature;
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
        if (sensorData[i].year == year)
        {
            sum += sensorData[i].temperature;
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
        if (sensorData[i].year == year)
        {
            if (sensorData[i].temperature < min)
            {
                min = sensorData[i].temperature;
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
        if (sensorData[i].year == year)
        {
            if (sensorData[i].temperature > max)
            {
                max = sensorData[i].temperature;
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
        if (sensorData[i].year == year && sensorData[i].month == month)
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
        if (sensorData[i].month == month)
        {

            int found = 0;
            for (size_t j = 0; j < yearsCount; j++)
            {
                if (years[j] == sensorData[i].year)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                years[yearsCount++] = sensorData[i].year;
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

void printAllRecords() {
    printf("\n=== All Temperature Records ===\n");
    printf("+-------+-------------+--------+------------+\n");
    printf("| Index | Date (Y-M-D)| Time   | Temp.      |\n");
    printf("+-------+-------------+--------+------------+\n");
    
    for (size_t i = 0; i < recordsCount; i++) {
        printf("| %-5zu | %04d-%02d-%02d  | %02d:%02d  | %+4d°C     |\n",
               i,
               sensorData[i].year,
               sensorData[i].month,
               sensorData[i].day,
               sensorData[i].hours,
               sensorData[i].minutes,
               sensorData[i].temperature);
    }
    
    if (recordsCount == 0) {
        printf("|       No records available             |\n");
    }
    
    printf("+-------+-------------+--------+------------+\n");
    printf("Total records: %zu\n", recordsCount);
}