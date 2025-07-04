/**
 * @file menu.h
 * @brief Заголовочный файл для функций меню
 */

#pragma once

/**
 * @brief Отображает главное меню
 */
void displayMainMenu();

/**
 * @brief Обрабатывает выбор пользователя в меню
 * @param choice Выбранный пункт меню
 */
void handleUserChoice(int choice);

/**
 * @brief Отображает меню добавления записи
 */
void displayAddRecordMenu();

/**
 * @brief Отображает меню удаления записи
 */
void displayRemoveRecordMenu();

/**
 * @brief Отображает меню статистики
 */
void displayStatsMenu();

/**
 * @brief Обрабатывает загрузку данных из файла
 */
void loadDataFromFile();

/**
 * @brief Отображает все записи
 */
void displayAllRecordsMenu();