#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
                 Вторая с конца ноль
    Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.

    Формат входных данных
    10 целых чисел через пробел.

    Формат результата
    Целые числа через пробел, у котороых вторая с конца цифра - ноль
*/

bool initArray(int *array, int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1) return true;
        array[i] = n;
    }

    return false;
}

void printArray(const int *array, const int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main(){
    const int SIZE = 10;
    int array[SIZE];

    if(initArray(array, SIZE)) abort();    

    printArray(array, SIZE);

    return 0;
}