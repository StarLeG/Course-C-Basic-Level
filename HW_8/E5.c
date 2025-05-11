#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Сумма положительных элементов
    Считать массив из 10 элементов и посчитать сумму положительных элементов массива.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    Одно целое число - сумма положительных элементов массива
*/

bool initArray(int *array, int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1) return true;
        array[i] = n;
    }

    return false;
}

int positiveSum(int *array, int size){
    int retValue = 0;

    for(int i = 0; i < size; i++){
        if(array[i] > 0) retValue += array[i];
    }


    return retValue;
}

int main(){

    const int SIZE = 10;
    int array[SIZE];

    if(initArray(array, SIZE)) abort();

    printf("%d\n", positiveSum(array, SIZE));

    return 0;
}