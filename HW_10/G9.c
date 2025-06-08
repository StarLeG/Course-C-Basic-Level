/*
    Удалить повторяющиеся символы
    В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
    Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.

    Формат входных данных
    Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов.

    Формат результата
    Строка из меленьких и больших английских букв.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1000

void removeDublicateAndSpace(char *str){
    if (str == NULL) return;
    bool seen[256] = {false};
    int len = strlen(str);
    int new_index = 0;

    for (int i = 0; i < len; i++) {
        unsigned char c = str[i];
        if (c == ' ') {
            continue;
        }
        if (!seen[c]) {
            seen[c] = true;
            str[new_index++] = c;
        }
    }
    str[new_index] = '\0'; 
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
       return -1;
    } 
    
    fclose(input);

    buffer[strcspn(buffer, "\n")] = '\0';

    removeDublicateAndSpace(buffer);
   

    fprintf(output, "%s", buffer);

    
    fclose(output);  
    
    

    return 0;
}