/*
                    Разобрать на слова
    В файле input.txt дано предложение требуется разобрать его на отдельные слова.
    Напечатать каждое слово на отдельной строке в файл output.txt.

    Формат входных данных
    Одна строка из английских букв и пробелов не более 1000 символов.

    Формат результата   
    Каждое слово на отдельной строке
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 1001

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input == NULL || output == NULL){
        printf("Error code: %d\n", errno);               
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    char buffer[SIZE] = {'\0'};

    if(fgets(buffer, sizeof(buffer), input) == NULL){                       
        fputs("The file is empty or reading error.\n", stderr);  
        return -1;      
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    char buf[SIZE] = {'\0'};
    int idx = 0;
    
    bool lastWasSpace = false;
   
    
    for (int i = 0; buffer[i] != '\0' && idx < SIZE - 1; i++) { 
      
        if (isspace(buffer[i])) {
            if (!lastWasSpace) {  
                buf[idx++] = '\n';
                lastWasSpace = true;
            }
        } else {
            buf[idx++] = buffer[i];
            lastWasSpace = false;
        }
    }
    
    if(buf[0] == '\n'){
        int len = strlen(buf);

        for(int i = 0; buf[i] != '\0'; i++){
            buf[i] = buf[i + 1];
        }

        buf[len - 1] = '\0';
    }
   

    fprintf(output, "%s", buf);

    fclose(input);
    fclose(output);

    return 0;
}