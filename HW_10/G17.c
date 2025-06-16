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
#include <ctype.h>

#define LEN 1001

void swap(char *ch1, char *ch2)
{
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void swapPairs(char *str)
{
    if (str == NULL)
        return;
    int len = strlen(str);
    int i = 0, j = 0;

    while (i < len && isspace(str[i]))
        i++;

    for (; i < len; i++)
    {
        if (!isspace(str[i]))
        {
            
            j = i + 1;
            while (j < len && isspace(str[j]))
                j++;

            if (j < len && !isspace(str[j]))
            {
                swap(&str[i], &str[j]);
                i = j; 
            }
            else
            {
                break; 
            }
        }
    }
}

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

    if (fgets(buffer, sizeof(buffer), input) == NULL)
    {
        fputs("The file is empty or reading error.\n", stderr);
        return -1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    swapPairs(buffer);

    fprintf(output, "%s", buffer);

    fclose(input);
    fclose(output);

    return 0;
}