/*
    Проверка на палиндром
    Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле
    получить одно слово - палиндром. Ответ напечатать на стандартный поток вывода.
    Требуется реализовать логическую функцию и применить ее.
    is_palindrom(string)

    Формат входных данных
    Строка из маленьких английских букв и пробелов. Не более 1000 символов.

    Формат результата
    YES или NO
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 1001

bool is_palindrome_possible(const int freq[]) {
    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd_count++;
        }
        if (odd_count > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    char buffer[LEN] = {'\0'};
    if (fgets(buffer, sizeof(buffer), input) == NULL) {
        fputs("The file is empty or reading error.\n", stderr);
        fclose(input);
        return -1;
    }
    fclose(input);

    buffer[strcspn(buffer, "\n")] = '\0';

    int freq[26] = {0};
    int len = strlen(buffer);

    for (int i = 0; i < len; i++) {
        if (isalpha(buffer[i])) {
            freq[buffer[i] - 'a']++;
        }
    }

    if (is_palindrome_possible(freq)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    getchar();
    return 0;
}