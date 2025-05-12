#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
        Циклический сдвиг массива вправо
    Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически
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

void arrayRotateRight(int *array, int size, int shift){

  
    
}

int main(){
    const int SIZE = 10;
    int array[SIZE];

    if(initArray(array, SIZE)) abort();

    arrayRotateRight(array, SIZE, 1);  
    
    printArray(array, SIZE);

    return 0;
}