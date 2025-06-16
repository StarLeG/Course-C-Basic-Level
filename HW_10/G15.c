/*
                        Cao заменить на Ling
    В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.

    Формат входных данных
    Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов.

    Формат результата
    Строка из английский букв, знаков препинания и пробелов.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define LEN 1001

void raplace(char *str){
    char *pos = NULL;
    int caoLen = strlen("Cao");
    int lingLen = strlen("Ling");

    while ((pos = strstr(str,"Cao")) != NULL)
    {
       if((pos == str || *(pos - 1) == ' ') && 
            (*(pos + caoLen) == ' ' || *(pos + caoLen) == '\0' || ispunct(*(pos + caoLen)))){
                memmove(pos + lingLen, pos + caoLen, strlen(pos + caoLen) + 1);
                memcpy(pos, "Ling", lingLen);
            }else{
                str = pos + caoLen;
            }
    }
    

}

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

    raplace(buffer);

    fprintf(output, "%s", buffer);

    fclose(input);
    fclose(output);

    return 0;

}