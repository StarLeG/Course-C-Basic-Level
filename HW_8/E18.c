#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                Кратность прежде всего
    В диапазоне натуральных чисел от 2 до N определить,
    сколько из них кратны любому из чисел в диапазоне от 2 до 9.

    Формат входных данных
    Одно целое число N большее 2 и не превосходящее 10000

    Формат результата
    Все числа от 2 до 9 в формате: 2 количество чисел кратных 2 3 количество чисел кратных 3 4
    количество чисел кратных 4 5 количество чисел кратных 5 6 количество чисел кратных 6 7
    количество чисел кратных 7 8 количество чисел кратных 8 9 количество чисел кратных 9
*/

void checkIfMultiple(int array[], const int size, const int num, const int multiplicity){    
    
    int cnt = 0;

    for(int i = 2; i <= num; i++){        
        if(i % multiplicity == 0) cnt++;
    }
    array[multiplicity] = cnt;

}

void printArray(const int array[], const int size, const int begin){
    for(int i = begin; i < size; i++){        
        printf("%d %d\n", i, array[i]);        
    }
}

int main(){
    #define SIZE 10
    int array[SIZE] = {0};

    int num = 0;
    if(scanf("%d", &num) != 1 || num > 10000 || num < 2) abort();

    for(int i = 2; i < SIZE; i++){
        checkIfMultiple(array, SIZE, num, i);
    }

    printArray(array, SIZE, 2);

    return 0;

}