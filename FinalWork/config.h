/**
 * @file config.h
 * @brief Конфигурационные константы и структуры данных
 * @author Старинский Олег Григорьевич
 * @date 2025 
 */

#pragma once

#include <stdint.h>

/** 
 * @def MAX_RECORDS
 * @brief Максимальное количество температурных записей в программе
 * @warning Превышение этого значения приведет к ошибке BUFFER_OVERFLOW
 */
#define MAX_RECORDS 527040

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
 * @details Содержит полную информацию о моменте измерения температуры
 */
typedef struct {
    /** 
     * @brief Год измерения (1900-2100)
     * @warning Значения вне диапазона считаются невалидными
     */
    uint16_t year;

    /** 
     * @brief Месяц измерения (1-12)
     * @note 1 - Январь, ..., 12 - Декабрь
     */
    uint8_t month;

    /** 
     * @brief День измерения (1-31)
     * @details Автоматически валидируется в зависимости от месяца
     */
    uint8_t day;

    /** 
     * @brief Часы измерения (0-23)
     * @note 24-часовой формат
     */
    uint8_t hours;

    /** 
     * @brief Минуты измерения (0-59)
     */
    uint8_t minutes;

    /** 
     * @brief Значение температуры (-99..+99 °C)
     * @warning Значения за пределами диапазона отбрасываются
     */
    int8_t temperature;
} TemperatureRecord;

/**
 * @brief Узел односвязного списка для TemperatureRecord
 * @details Используется для организации связного списка записей
 */
typedef struct TemperatureNode {
    /** 
     * @brief Данные температурной записи
     * @see TemperatureRecord
     */
    TemperatureRecord data;

    /** 
     * @brief Указатель на следующий узел списка
     * @warning NULL для последнего элемента
     */
    struct TemperatureNode* next;
} TemperatureNode;