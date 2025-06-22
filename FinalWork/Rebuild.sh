#!/bin/bash

# Запуск make rebuild
make rebuild || {
    echo "Ошибка при выполнении make rebuild"
    exit 1
}

echo "Команда make rebuild успешно выполнена"
exit 0