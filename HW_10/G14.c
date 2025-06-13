/*
    В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt,
    где останутся имя и фамилия

    Формат входных данных
    Строка состоящая из английских букв и пробелов не более 100 символов. Формат: Фамилия Имя Отчество
    
    Формат результата
    Строка состоящая из английских букв и пробелов
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define LEN 100

struct FullName{
    char firstName[50]; 
    char lastName[50];  
    char patronymic[50];
};

typedef struct FullName FullName_t;

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

    FullName_t fullName;

    

    fclose(input);
    fclose(output);

    return 0;
}
