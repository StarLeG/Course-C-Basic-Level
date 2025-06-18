/*
    Равносторонние треугольники
    Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней.
    Ling дал Cia камни и попросил его составить такой треугольник если это возможно.
    Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно.
    Пример треугольников, которые составляет Cia:

         *
        * *

          *
         * *
        * * *

           *
          * *
         * * *
        * * * *
    Во входном файле input.txt записано некоторое количество символов * (камней).
    Необходимо построить равносторонний треугольник используя все символы * и символ пробел,
    записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел. Если треугольник невозможно составить,
    используя все камни, то необходимо записать единственное слово NO в файл output.txt.

    Формат входных данных
    Текстовый файл состоит из различных символов и символов *.
    
    Формат результата
    Равносторонний треугольник составленный из символов *, символов пробела и символов переноса строк или слово NO.
*/


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 1001

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

    fclose(input);
    fclose(output);

    return 0;
}