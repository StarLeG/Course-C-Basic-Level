/*
                Ling заменить на Cao
    В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на «Cao» и результат записать в файл output.txt.

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

void raplace(char *str, const int caseValue)
{
    char *pos = NULL;
    int caoLen = strlen("Cao");
    int lingLen = strlen("Ling");

    switch (caseValue)
    {
    case 1:
        while ((pos = strstr(str, "Ling")) != NULL)
        {

            if ((pos == str || *(pos - 1) == ' ') &&
                (*(pos + lingLen) == ' ' || *(pos + lingLen) == '\0' || ispunct(*(pos + lingLen))))
            {
                memmove(pos + caoLen, pos + lingLen, strlen(pos + lingLen) + 1);
                memcpy(pos, "Cao", caoLen);
            }
            else
            {
                str = pos + caoLen;
            }
        }
        break;
    case 2:
        while ((pos = strstr(str, "Ling")) != NULL)
        {
            memmove(pos + caoLen, pos + lingLen, strlen(pos + lingLen) + 1);
            memcpy(pos, "Cao", caoLen);
        }
        break;
    default:
        break;
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
        //fputs("The file is empty or reading error.\n", stderr);
        return 0;
        
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    raplace(buffer, 2);

    fprintf(output, "%s", buffer);

    fclose(input);
    fclose(output);

    return 0;
}