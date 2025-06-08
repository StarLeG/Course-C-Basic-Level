/*
                                            Самое длинное слово
    В файле input.txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл output.txt.
    Случай, когда самых длинных слов может быть несколько, не обрабатывать.

    Формат входных данных
    Строка из английских букв и пробелов. Не более 1000 символов.

    Формат результата
    Одно слово из английских букв.
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define SIZE 1001

void findLongestWord(const char *str, char *buffer){
    if(str == NULL) return;

    int maxLen = 0;        
    const char *maxWord = NULL; 

    while (*str != '\0') {       
        while (*str == ' ') {
            str++;
        }

        if (*str == '\0') {
            break; 
        }

       
        int len = strcspn(str, " ");        
        
        if (len > maxLen) {
            maxLen = len;
            maxWord = str;
        }
        
        str += len;
    }

    
    if (maxWord != NULL) {
        strncpy(buffer, maxWord, maxLen);
        buffer[maxLen] = '\0'; 
    } else {
        buffer[0] = '\0'; 
    }   

} 

int main(){
    char buffer[SIZE] = {'\0'};

    FILE *input = fopen("input.txt", "r");
    if(input == NULL){
        printf("Error code: %d\n", errno);               
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    if(fgets(buffer, sizeof(buffer), input) == NULL){                       
        fputs("The file is empty or reading error.\n", stderr);        
    }

    fclose(input);

    char longestWord[SIZE] = {'\0'};

    findLongestWord(buffer, longestWord);

    FILE *output = fopen("output.txt", "w");
    if(input == NULL){
        printf("Error code: %d\n", errno);               
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    fprintf(output, "%s", longestWord);

    fclose(output);


    return 0;
}