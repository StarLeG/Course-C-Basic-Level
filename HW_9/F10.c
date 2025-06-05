/*
                        Упаковать строку
    Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка.
    Необходимо заменить повторяющиеся буквы на <буква><количество повторений>

    Формат входных данных
    Входная строка состоящая из букв 'a'-'z' не превышающая 1000 символов. В конце строки символ '.'

    Формат результата
    Результат состоящий из букв и чисел, без пробелов
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 1000

int main(){
    char buffer[SIZE] = {'\0'};
    char ch;
    int idx = 0;
    int cnt = 0; 
    int end = 0;   
    
    while (idx < SIZE - 1 && scanf("%c", &ch) == 1 && ch != '.') {
        buffer[idx++] = ch;
    }   

   for (int i = 0; i < idx; ) {
        char current = buffer[i];
        int count = 1;        
       
        while (i + count < idx && buffer[i + count] == current) {
            count++;
        }        
        
        printf("%c%d", current, count);        
        
        i += count;
    }
    
    printf("\n");

    system("pause");
    return 0;
    
}
