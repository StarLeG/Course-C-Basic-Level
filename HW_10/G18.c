/*
                        Удалить пробелы из текста
    В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
    Для решения задачи разработать функцию. Результат записать в output.txt.

    Формат входных данных
    Строка из английских букв, знаков препинания и пробелов. Не более 1000 символов.

    Формат результата
    Строка из английских букв, знаков препинания и пробелов.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 1001

void removeSpaces(char *str)
{
    if (str == NULL || *str == '\0')
        return;

    int i = 0, j = 0;
    int len = strlen(str);

    while (isspace(str[i]))
        i++;

    bool spaceFlag = false;

    for (; i < len; i++)
    {
        if (isspace(str[i]))
        {
            if (!spaceFlag)
            {
                str[j++] = ' ';
                spaceFlag = true;
            }
        }
        else
        {
            str[j++] = str[i];
            spaceFlag = false;
        }
    }

    if (j > 0 && isspace(str[j - 1])) j--;
    str[j] = '\0';
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

    removeSpaces(buffer);

    fprintf(output, "%s", buffer);

    fclose(input);
    fclose(output);

    return 0;
}