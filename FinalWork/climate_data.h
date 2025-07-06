/**
 * @file climate_data.h
 * @brief Заголовочный файл для работы с данными о температуре
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include "config.h"

extern TemperatureRecord sensorData[MAX_RECORDS];
extern size_t recordsCount;

/**
 * @brief Добавляет новую запись о температуре
 * @param year Год записи
 * @param month Месяц записи (1-12)
 * @param day День записи
 * @param hours Часы записи (0-23)
 * @param minutes Минуты записи (0-59)
 * @param temperature Значение температуры (-99 до 99)
 */
void addRecord(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature);

/**
 * @brief Удаляет запись по индексу
 * @param index Индекс записи для удаления
 */
void removeRecord(size_t index);

/**
 * @brief Находит и удаляет конкретную запись
 * @param year Год для поиска
 * @param month Месяц для поиска (1-12)
 * @param day День для поиска
 * @param hours Часы для поиска (0-23)
 * @param minutes Минуты для поиска (0-59)
 * @param temperature Температура для поиска
 * @return int 1 если найдена и удалена, 0 в противном случае
 */
int findAndRemoveRecord(uint16_t year, uint8_t month, uint8_t day, 
                       uint8_t hours, uint8_t minutes, int8_t temperature);

/**
 * @brief Подсчитывает записи за конкретный месяц
 * @param year Год для подсчета
 * @param month Месяц для подсчета (1-12)
 * @return size_t Количество найденных записей
 */                       
size_t countMonthlyRecords(uint16_t year, uint8_t month);

/**
 * @brief Выводит месячную статистику за год
 * @param year Год для вывода статистики
 */
void printMonthlyStats(uint16_t year);

/**
 * @brief Выводит годовую статистику
 * @param year Год для вывода статистики
 */
void printYearlyStats(uint16_t year);

/**
 * @brief Выводит статистику по конкретному месяцу за все годы
 * @param month Месяц для вывода статистики (1-12)
 */
void printStatsForMonthAllYears(uint8_t month);

/**
 * @brief Выводит все записи в форматированной таблице
 */
void printAllRecords();

/**
 * @brief Получает среднюю температуру за месяц
 * @param year Год для проверки
 * @param month Месяц для проверки (1-12)
 * @return float Средняя температура
 */
float getAverageMonthlyTemp(uint16_t year, uint8_t month);

/**
 * @brief Получает минимальную температуру за месяц
 * @param year Год для проверки
 * @param month Месяц для проверки (1-12)
 * @return int8_t Минимальная температура
 */
int8_t getMinMonthlyTemp(uint16_t year, uint8_t month);

/**
 * @brief Получает максимальную температуру за месяц
 * @param year Год для проверки
 * @param month Месяц для проверки (1-12)
 * @return int8_t Максимальная температура
 */
int8_t getMaxMonthlyTemp(uint16_t year, uint8_t month);

/**
 * @brief Получает среднюю температуру за год
 * @param year Год для проверки
 * @return float Средняя температура
 */
float getAverageYearlyTemp(uint16_t year);

/**
 * @brief Получает минимальную температуру за год
 * @param year Год для проверки
 * @return int8_t Минимальная температура
 */
int8_t getMinYearlyTemp(uint16_t year);

/**
 * @brief Получает максимальную температуру за год
 * @param year Год для проверки
 * @return int8_t Максимальная температура
 */
int8_t getMaxYearlyTemp(uint16_t year);

