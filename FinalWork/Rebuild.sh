#!/bin/bash

# Определяем операционную систему
OS="$(uname -s)"

# Функция для проверки и выполнения make rebuild
run_make_rebuild() {
    local make_cmd="make"
    
    # В Windows используем mingw32-make вместо make
    case "${OS}" in
        MINGW*|CYGWIN*|MSYS*) make_cmd="mingw32-make" ;;
    esac

    if ! ${make_cmd} rebuild; then
        echo "Ошибка при выполнении ${make_cmd} rebuild"
        return 1
    fi
    return 0
}

# Основная логика
case "${OS}" in
    Linux*|MINGW*|CYGWIN*|MSYS*)
        # Для Linux (Ubuntu) и Windows (Git Bash, Cygwin, MSYS2)
        run_make_rebuild || exit 1
        ;;
    *)
        echo "Неподдерживаемая операционная система: ${OS}"
        exit 1
        ;;
esac

echo "Команда rebuild успешно выполнена"
exit 0