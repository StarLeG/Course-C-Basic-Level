/*
                Изменить расширение
    В файле input.txt записан полный адрес файла (возможно, без расширения). Необходимо изменить его расширение на ".html" 
    и записать результат в файл output.txt.

    Формат входных данных
    Строка состоящая из символов: a-z, A-Z, 0-9, /

    Формат результата
    Исходная строка с измененным расширением.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define LEN 1000  

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    char buffer[LEN] = {'\0'};

    if (fgets(buffer, sizeof(buffer), input) == NULL) {
        fputs("The file is empty or reading error.\n", stderr);
        return -1;
    }

    
    buffer[strcspn(buffer, "\n")] = '\0';

    
    char *last_dot = strrchr(buffer, '.');
    char *last_slash = strrchr(buffer, '/');

   
    if (last_dot != NULL && (last_slash == NULL || last_dot > last_slash)) {        
        *last_dot = '\0';
    }    
   
    fprintf(output, "%s.html", buffer);

    fclose(input);
    fclose(output);

    return 0;
}