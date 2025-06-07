/*
                             По одному разу
    В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
    Найдите только те символы слов, которые встречаются в обоих словах только один раз.
    Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

    Формат входных данных
    Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
    
    Формат результата
    Маленькие английские буквы через пробел.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 101
#define MAX_CHARS 256

void countChars(const char *word, int *charCount) {
    for (int i = 0; word[i] != '\0'; i++) {
        charCount[(unsigned char)word[i]]++;
    }
}

void getUniqueChars(const int *charCount, char *uniqueChars) {
    int idx = 0;
    for (int i = 0; i < MAX_CHARS; i++) {
        if (charCount[i] == 1) {
            uniqueChars[idx++] = (char)i;
        }
    }
    uniqueChars[idx] = '\0';
}

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input == NULL || output == NULL){        
        fputs("Error opening file.\n", stderr);
        return -1;
    }

    char str_1[SIZE] = {'\0'};
    char str_2[SIZE] = {'\0'};

    if(fscanf(input, "%s%s", str_1, str_2) != 2){
        fputs("Error attempting to read file.\n", stderr);
        return -1;
    }

    str_1[strcspn(str_1, "\n")] = '\0';
    str_2[strcspn(str_2, "\n")] = '\0';

    int count1[MAX_CHARS] = {0};
    int count2[MAX_CHARS] = {0};

    countChars(str_1,count1);
    countChars(str_2,count2);

    char unique1[MAX_CHARS];
    char unique2[MAX_CHARS];

    getUniqueChars(count1, unique1);
    getUniqueChars(count2, unique2);

    for (int i = 0; unique1[i] != '\0'; i++) {
        for (int j = 0; unique2[j] != '\0'; j++) {
            if (unique1[i] == unique2[j]) {
                fprintf(output, "%c ", unique1[i]);
                break;
            }
        }
    }



    fclose(input);
    fclose(output);   

    return 0;
}