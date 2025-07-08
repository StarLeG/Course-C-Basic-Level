/**
 * @file readFileToBuffer.h
 * @brief Заголовочный файл для функций чтения файлов
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "config.h"

/**
 * @def SUCCESS
 * @brief Код успешного выполнения операции
 * @details Возвращается при корректном завершении функции без ошибок
 */
#define SUCCESS 0

/**
 * @def FILE_OPEN_ERROR
 * @brief Ошибка открытия файла
 * @details Возвращается когда файл не может быть открыт (не найден, нет прав доступа и т.д.)
 */
#define FILE_OPEN_ERROR -1

/**
 * @def INVALID_FORMAT
 * @brief Ошибка формата данных
 * @details Возвращается при несоответствии формата данных ожидаемому (например, некорректный CSV)
 */
#define INVALID_FORMAT -2

/**
 * @def BUFFER_OVERFLOW
 * @brief Переполнение буфера
 * @details Возвращается при попытке добавить запись сверх установленного лимита MAX_RECORDS
 */
#define BUFFER_OVERFLOW -3

/**
 * @def INVALID_EXTENSION
 * @brief Некорректное расширение файла
 * @details Возвращается когда файл имеет недопустимое расширение (требуется .csv)
 */
#define INVALID_EXTENSION -4

/**
 * @def INVALID_PARAM
 * @brief Некорректный параметр
 * @details Возвращается при передаче недопустимых параметров в функцию (например, NULL вместо имени файла)
 */
#define INVALID_PARAM -5

/**
 * @brief Читает содержимое файла в буфер
 * @param fileName Имя файла для чтения 
 * @return int Код статуса (0 при успехе, отрицательный при ошибках)
 */
int readFileToBuffer(char *fileName);