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
 * @brief Читает содержимое файла в буфер
 * @param fileName Имя файла для чтения
 * @param buffer Буфер для хранения содержимого
 * @return int Код статуса (0 при успехе, отрицательный при ошибках)
 */

int readFileToBuffer(char *fileName, char *buffer);