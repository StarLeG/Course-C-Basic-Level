/**
 * @file config.h
 * @brief Конфигурационные константы и структуры данных
 */

#pragma once

#include <stdint.h>

/** 
 * @def SIZE
 * @brief Максимальный размер буфера для чтения файлов (в байтах)
 */
#define SIZE 1000000

/** 
 * @def MAX_RECORDS
 * @brief Максимальное количество температурных записей в программе
 * @warning Превышение этого значения приведет к ошибке BUFFER_OVERFLOW
 */
#define MAX_RECORDS 900000

/** 
 * @def RED_TEXT
 * @brief ANSI-код для вывода текста красным цветом в терминале
 * @note Используется для сообщений об ошибках
 */
#define RED_TEXT "\x1B[31m"

/** 
 * @def GREEN_TEXT
 * @brief ANSI-код для вывода текста зеленым цветом в терминале
 * @note Используется для успешных операций
 */
#define GREEN_TEXT "\x1B[32m"

/** 
 * @def RESET_TEXT
 * @brief ANSI-код для сброса цветового форматирования в терминале
 * @note Должен использоваться после цветных сообщений
 */
#define RESET_TEXT "\x1B[0m"

/**
 * @brief Структура для хранения данных о температуре
 */
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temperature;
} TemperatureRecord;

/**
 * @brief Узел односвязного списка для TemperatureRecord
 */
typedef struct TemperatureNode {
    TemperatureRecord data;
    struct TemperatureNode* next;
} TemperatureNode;