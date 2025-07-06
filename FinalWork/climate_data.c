/**
 * @file climate_data.c
 * @brief Реализация функций работы с данными о температуре
 */

#include "climate_data.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

TemperatureNode *sensorDataHead = NULL;
size_t recordsCount = 0;

/**
 * @brief Проверяет корректность данных температуры
 */
static bool isValidRecord(uint16_t year, uint8_t month, uint8_t day,
                         uint8_t hours, uint8_t minutes, int8_t temp)
{
    return (year >= 1900 && year <= 2100) &&  // Added year validation
           (month >= 1 && month <= 12) &&
           (day >= 1 && day <= 31) &&
           (hours <= 23) &&
           (minutes <= 59) &&
           (temp >= -99 && temp <= 99);
}

/**
 * @brief Добавляет новую запись о температуре
 */
void addRecord(uint16_t year, uint8_t month, uint8_t day,
               uint8_t hours, uint8_t minutes, int8_t temperature)
{

    if (recordsCount >= MAX_RECORDS || !isValidRecord(year, month, day, hours, minutes, temperature))
    {
        return;
    }

    TemperatureNode *newNode = (TemperatureNode *)malloc(sizeof(TemperatureNode));
    if (!newNode)
    {
        return;
    }

    newNode->data.year = year;
    newNode->data.month = month;
    newNode->data.day = day;
    newNode->data.hours = hours;
    newNode->data.minutes = minutes;
    newNode->data.temperature = temperature;
    newNode->next = NULL;

    if (!sensorDataHead)
    {
        sensorDataHead = newNode;
    }
    else
    {
        TemperatureNode *current = sensorDataHead;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    recordsCount++;
}

/**
 * @brief Удаляет запись по индексу
 */
void removeRecord(size_t index)
{
    if (index >= recordsCount || !sensorDataHead)
    {
        return;
    }

    TemperatureNode *toDelete = NULL;

    if (index == 0)
    {
        toDelete = sensorDataHead;
        sensorDataHead = sensorDataHead->next;
    }
    else
    {
        TemperatureNode *current = sensorDataHead;
        for (size_t i = 0; i < index - 1 && current->next; i++)
        {
            current = current->next;
        }

        if (!current->next)
        {
            return;
        }

        toDelete = current->next;
        current->next = toDelete->next;
    }

    free(toDelete);
    recordsCount--;
}

/**
 * @brief Находит и удаляет конкретную запись
 */
int findAndRemoveRecord(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hours, uint8_t minutes, int8_t temperature)
{
    TemperatureNode *current = sensorDataHead;
    TemperatureNode *prev = NULL;
    size_t index = 0;

    while (current)
    {
        if (current->data.year == year &&
            current->data.month == month &&
            current->data.day == day &&
            current->data.hours == hours &&
            current->data.minutes == minutes &&
            current->data.temperature == temperature)
        {

            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                sensorDataHead = current->next;
            }

            free(current);
            recordsCount--;
            return 1;
        }

        prev = current;
        current = current->next;
        index++;
    }

    return 0;
}

/**
 * @brief Получает среднюю температуру за месяц
 */
float getAverageMonthlyTemp(uint16_t year, uint8_t month)
{
    int sum = 0;
    int count = 0;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        if (current->data.year == year && current->data.month == month)
        {
            sum += current->data.temperature;
            count++;
        }
        current = current->next;
    }

    return count > 0 ? (float)sum / count : 0;
}

/**
 * @brief Получает минимальную температуру за месяц
 */
int8_t getMinMonthlyTemp(uint16_t year, uint8_t month)
{
    int8_t min = INT8_MAX;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        if (current->data.year == year && current->data.month == month)
        {
            if (current->data.temperature < min)
            {
                min = current->data.temperature;
            }
        }
        current = current->next;
    }

    return min != INT8_MAX ? min : 0;
}

/**
 * @brief Получает максимальную температуру за месяц
 */
int8_t getMaxMonthlyTemp(uint16_t year, uint8_t month)
{
    int8_t max = INT8_MIN;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        if (current->data.year == year && current->data.month == month)
        {
            if (current->data.temperature > max)
            {
                max = current->data.temperature;
            }
        }
        current = current->next;
    }

    return max != INT8_MIN ? max : 0;
}

/**
 * @brief Получает среднюю температуру за год
 */
float getAverageYearlyTemp(uint16_t year)
{
    int sum = 0;
    int count = 0;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        if (current->data.year == year)
        {
            sum += current->data.temperature;
            count++;
        }
        current = current->next;
    }

    return count > 0 ? (float)sum / count : 0;
}

/**
 * @brief Получает минимальную температуру за год
 */
int8_t getMinYearlyTemp(uint16_t year)
{
    int8_t min = INT8_MAX;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        if (current->data.year == year)
        {
            if (current->data.temperature < min)
            {
                min = current->data.temperature;
            }
        }
        current = current->next;
    }

    return min != INT8_MAX ? min : 0;
}

/**
 * @brief Получает максимальную температуру за год
 */
int8_t getMaxYearlyTemp(uint16_t year)
{
    int8_t max = INT8_MIN;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        if (current->data.year == year)
        {
            if (current->data.temperature > max)
            {
                max = current->data.temperature;
            }
        }
        current = current->next;
    }

    return max != INT8_MIN ? max : 0;
}

/**
 * @brief Подсчитывает записи за конкретный месяц
 */
size_t countMonthlyRecords(uint16_t year, uint8_t month)
{
    size_t count = 0;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        if (current->data.year == year && current->data.month == month)
        {
            count++;
        }
        current = current->next;
    }

    return count;
}

/**
 * @brief Выводит месячную статистику за год
 */
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

/**
 * @brief Выводит годовую статистику
 */
void printYearlyStats(uint16_t year)
{
    printf("Year %d Statistics:\n", year);
    printf("  Average: %.1f°C\n", getAverageYearlyTemp(year));
    printf("  Min: %d°C\n", getMinYearlyTemp(year));
    printf("  Max: %d°C\n", getMaxYearlyTemp(year));
}

/**
 * @brief Выводит статистику по конкретному месяцу за все годы
 */
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
    TemperatureNode *current = sensorDataHead;

    // Собираем все уникальные годы для указанного месяца
    while (current)
    {
        if (current->data.month == month)
        {
            int found = 0;
            for (size_t j = 0; j < yearsCount; j++)
            {
                if (years[j] == current->data.year)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                years[yearsCount++] = current->data.year;
            }
        }
        current = current->next;
    }

    // Выводим статистику для каждого года
    for (size_t i = 0; i < yearsCount; i++)
    {
        printf("Year %d:\n", years[i]);
        printf("  Average: %.1f°C\n", getAverageMonthlyTemp(years[i], month));
        printf("  Min: %d°C\n", getMinMonthlyTemp(years[i], month));
        printf("  Max: %d°C\n", getMaxMonthlyTemp(years[i], month));
        printf("\n");
    }
}

/**
 * @brief Выводит все записи в форматированной таблице
 */
void printAllRecords()
{
    printf("\n=== All Temperature Records ===\n");
    printf("+-------+-------------+--------+------------+\n");
    printf("| Index | Date (Y-M-D)| Time   | Temp.      |\n");
    printf("+-------+-------------+--------+------------+\n");

    size_t index = 0;
    TemperatureNode *current = sensorDataHead;

    while (current)
    {
        printf("| %-5zu | %04d-%02d-%02d  | %02d:%02d  | %+4d°C     |\n",
               index,
               current->data.year,
               current->data.month,
               current->data.day,
               current->data.hours,
               current->data.minutes,
               current->data.temperature);

        current = current->next;
        index++;
    }

    if (recordsCount == 0)
    {
        printf("|       No records available             |\n");
    }

    printf("+-------+-------------+--------+------------+\n");
    printf("Total records: %zu\n", recordsCount);
}

/**
 * @brief Освобождает память, занятую списком
 */
void freeTemperatureList()
{
    TemperatureNode *current = sensorDataHead;
    while (current)
    {
        TemperatureNode *next = current->next;
        free(current);
        current = next;
    }
    sensorDataHead = NULL;
    recordsCount = 0;
}