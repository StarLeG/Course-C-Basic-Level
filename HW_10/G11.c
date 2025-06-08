/*
                        Заканчивается на a
    В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'.
    Ответ записать в файл output.txt.

    Формат входных данных
    Строка из английских букв и пробелов не более 1000 символов.

    Формат результата
    Одно целое число

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define SIZE 1001

int countWordsEndingWith_a(const char *str){
    if(str == NULL) return -1;
    bool cntSpace[SIZE] = {false};
    int retval = 0;
    bool oneWord = false;


    for (int i = 0; str[i] != '\0'; i++) {
        cntSpace[i] = (str[i] == ' ');  
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if(cntSpace[i]){
            oneWord = true;
            if(str[i - 1] == 'a' || str[i - 1] == 'A') retval++;
        }  
    }

    if(!oneWord){
        if(str[strlen(str) - 1] == 'a') retval++;
    }
    
    
    return retval;
}

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

    fclose(input);

    fprintf(output, "%d", countWordsEndingWith_a(buffer));

    fclose(output);

    return 0;
}