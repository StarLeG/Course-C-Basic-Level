/*
    Три раза
    В файле input.txt дана строка. Вывести ее в файл output.txt
    три раза через запятую и показать количество символов в ней.

    Формат входных данных
    Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.

    Формат результата
    Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    file = fopen("input.txt", "r");
    if(file == NULL){
        return -1;
    }

    char buffer[100] = {'\0'};

    fgets(buffer, sizeof(buffer), file);

    fclose(file);

    int size = strlen(buffer);

    file = fopen("output.txt", "w");

    for(int i = 0; i < 3; i++){
        fprintf(file,"%s", buffer);
        if(i < 2) fprintf(file,", ");
        if(i == 2) fprintf(file," %d", size);
    }

    fclose(file);

    return 0;
}
