/*
                            Составить палиндром
    Разработать функцию дана строка из маленьких английских букв.
    Составить из символов палиндром максимальной длинны.
    При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке.
    Записать ответ в файл output.txt.

    Формат входных данных
    Строка из маленьких английских букв. Не более 1000 символов.

    Формат результата
    Строка из маленьких английских букв.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 1001

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL)
    {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    char buffer[LEN] = {'\0'};

    if (fgets(buffer, sizeof(buffer), input) == NULL)
    {
        fputs("The file is empty or reading error.\n", stderr);
        return -1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    fclose(input);
    fclose(output);
}