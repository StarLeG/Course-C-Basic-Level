#include <stdio.h>
#include <stdlib.h>

/*
                        Найти минимум
    Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.

    Формат входных данных
    5 целых чисел через пробел

    Формат результата
    Одно единственное целое число
*/

void initArray(int *array, int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1) abort();
        array[i] = n;
    }
}

int find_MIN(int *array, int size){
    int retVal = array[0];

    for(int i = 1; i < size; i++){
        if (array[i] < retVal) retVal = array[i];
    }

    return retVal;
}

int main(){

    const int SIZE = 5;
    int array[SIZE];

    initArray(array, SIZE);

    printf("%d\n", find_MIN(array, SIZE));

    return 0;
}