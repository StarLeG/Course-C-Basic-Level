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

void countChars(const char *buffer,int freq[], const int len){
      for (int i = 0; i < len; i++) {
        if (isalpha(buffer[i])) {
            freq[buffer[i] - 'a']++;
        }
    }
}

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

    int freq[26] = {0};
    int len = strlen(buffer);    

    countChars(buffer, freq, len);

    char left[LEN] = {0}; 
    char middle = '\0';    
    int left_pos = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;
        
        int count = freq[i] / 2;
        for (int j = 0; j < count; j++) {
            left[left_pos++] = 'a' + i;
        }

        
        if (freq[i] % 2 != 0) {            
            if (middle == '\0' || ('a' + i) < middle) {
                middle = 'a' + i;
            }
        }
    }

    char right[LEN] = {0};
    for (int i = 0; i < left_pos; i++) {
        right[i] = left[left_pos - 1 - i];
    }
    right[left_pos] = '\0';

    char palindrome[LEN * 2] = {0};
    strcpy(palindrome, left);
    if (middle != '\0') {
        palindrome[left_pos] = middle;
        strcat(palindrome, right);
    } else {
        strcat(palindrome, right);
    }

    fprintf(output, "%s", palindrome);

    fclose(input);
    fclose(output);
}