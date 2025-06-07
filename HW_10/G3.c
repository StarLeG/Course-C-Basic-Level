/*
                                Последний номер символа
    В файле input.txt дана строка из не более 1000 символов. Показать номера символов, совпадающих с последним символом строки.
    Результат записать в файл output.txt

    Формат входных данных   
    Строка из не более 1000 символов
    Формат результата
    Целые числа через пробел - номера символа, который совпадает с последним символом строки.

*/

#include <stdio.h>
#include <string.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    char buffer[1001];
    if (fgets(buffer, sizeof(buffer), input) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    
    buffer[strcspn(buffer, "\n")] = '\0';

    int size = strlen(buffer);
    if (size == 0) {
        fclose(input);
        fclose(output);
        return 0;
    }

    char last_char = buffer[size - 1];
    int first = 1; 

    for (int i = 0; i < size - 1; i++) {
        if (buffer[i] == last_char) {
            if (!first) {
                fprintf(output, " ");
            }
            fprintf(output, "%d", i);
            first = 0;
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}