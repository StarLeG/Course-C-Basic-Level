#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
                            Цифры по возрастанию
    Написать функцию и программу демонстрирующую работу данной функции.
    Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N,
    не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в числе.

    Формат входных данных
    Натуральное число не более 1000 цифр

    Формат результата
    Цифры входящие в число через пробел в порядке возрастания. От самой младшей цифры до самой старшей и количество.
*/

void cntCharacters(const char* str, const int size){
    int aCnt[10] = {0};    

    for(int i = 0; i < size; i++){
         if (str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0'; 
            aCnt[digit]++;
        }
    }

    for(int i = 0; i < 10; i++){
        if(aCnt[i] > 0)
            printf("%d %d\n", i, aCnt[i]);
    }

}

int main(){
    #define SIZE 1000
    char buffer[SIZE];

    scanf("%s", buffer);

    int size = strlen(buffer);

    cntCharacters(buffer, size);        

    return 0;
}