/*
                    Заменить a на b
    В файле input.txt дана символьная строка не более 1000 символов.
    Необходимо заменить все буквы "а" на буквы "b" и наоборот,
    как заглавные, так и строчные. Результат записать в output.txt.

    Формат входных данных
    Строка из маленьких и больших английских букв, знаков препинания и пробелов.

    Формат результата
    Строка из маленьких и больших английских букв, знаков препинания и пробелов.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 1001

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

    int lenght = strlen(buffer);

    for(int i = 0; i < lenght; i++){
        if(buffer[i] == 'a' || buffer[i] == 'A'){
            if(buffer[i] == 'a') buffer[i] = 'b';
            if(buffer[i] == 'A') buffer[i] = 'B';
            continue;
        }

        if(buffer[i] == 'b' || buffer[i] == 'B'){
            if(buffer[i] == 'b') buffer[i] = 'a';
            if(buffer[i] == 'B') buffer[i] = 'A';
            continue;
        }
    }

    fprintf(output, "%s", buffer);

    fclose(input);
    fclose(output); 

    return 0;
}