/*
                        Пары соседних символов
    В файле input.txt записаны символы. Необходимо разработать функцию,
    которая меняет местами пары соседних символов не обращая внимание на символы пробел.
    Если количество символов нечетно (пробелы не считаем), то последний символ не меняем.
    Результат записать в файл output.txt.

    Формат входных данных   
    Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.

    Формат результата
    Строка из английских букв, пробелов и знаков препинания.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define LEN 1001

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input == NULL || output == NULL){
        printf("Error code: %d\n", errno);               
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    char buffer[LEN] = {'\0'};

    if(fgets(buffer, sizeof(buffer), input) == NULL){                       
        fputs("The file is empty or reading error.\n", stderr);  
        return -1;      
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    fclose(input);
    fclose(output);

    return 0;

}