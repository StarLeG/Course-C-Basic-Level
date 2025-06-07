/*
                    Проверка на палиндром
    В файле input.txt символьная строка не более 1000 символов.
    Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях).
    Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

    Формат входных данных
    Строка из заглавных английских букв

    Формат результата
    YES или NO
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1001

bool is_palindrom(const char *str){
    if (str == NULL) return false; 
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {        
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        
        
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;

}

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input == NULL || output == NULL){        
        fputs("Error opening file.\n", stderr);
        return -1;
    }

    char buffer[SIZE] = {'\0'};

    if(fgets(buffer, sizeof(buffer), input) == NULL){
       fputs("The file is empty or reading error.\n", stderr);
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    if(is_palindrom(buffer)){
        fprintf(output, "YES\n");
    }else{
        fprintf(output, "NO\n");
    }





    fclose(input);
    fclose(output); 

    return 0;
}