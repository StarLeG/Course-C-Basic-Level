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
    записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел.
    Если треугольник невозможно составить,
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

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL)
    {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    char buffer[LEN] = {'\0'};
    size_t starCount = 0;

    while (fgets(buffer, sizeof(buffer), input))
    {
        size_t len = strlen(buffer);
        for (size_t i = 0; i < len; i++)
        {
            if (buffer[i] == '*')
            {
                starCount++;
            }
        }
    }

    if (ferror(input))
    {
        fputs("Reading error..\n", stderr);
        return -1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    fclose(input);

    int n = 0;
    int total = 0;

    while (total < starCount)
    {
        n++;
        total = n * (n + 1) / 2;
    }

    if (total != starCount)
    {
        fprintf(output, "NO\n");
    }
    else
    {       
        for (int i = 1; i <= n; i++)
        {            
            for (int j = 0; j < n - i; j++)
            {
                fprintf(output, " ");
            }
                      
            for (int j = 0; j < i; j++)
            {
                if (j > 0)
                {
                    fprintf(output, " *");
                }
                else
                {
                    fprintf(output, "*");
                }
            }
            fprintf(output, "\n");
        }
    }

    fclose(output);

    return 0;
}