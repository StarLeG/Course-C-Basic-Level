/*
    Количество букв
    В файле input.txt считать символьную строку, не более 10 000 символов.
    Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке.
    Учитывать только английские буквы. Результат записать в файл output.txt.

    Формат входных данных
    Строка состоящая из английских букв, цифр, пробелов и знаков препинания.

    Формат результата
    Два целых числа. Количество строчных букв и количество заглавных букв.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10001

int count_lowercase(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            count++;
        }
    }
    return count;
}

int count_uppercase(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input == NULL || output == NULL){        
        fputs("Error opening file.\n", stderr);
        return -1;
    }

    char buffer[SIZE] = {'\0'};

    if(fgets(buffer, sizeof(buffer), input) == NULL){
       fputs("The file is empty or reading error.\n", stderr);
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    fprintf(output, "%d %d\n", count_lowercase(buffer), count_uppercase(buffer));

    fclose(input);
    fclose(output); 

    return 0;
}