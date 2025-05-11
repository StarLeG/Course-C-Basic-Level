#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                Инверсия каждой трети
    Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

    Формат входных данных
    12 целых чисел через пробел

    Формат результата
    12 целых чисел через пробел
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

void reverseArray(int *array, int size){

    
    int half = size / 3;

    for(int i = 0; i < (half / 2); i++){
        int temp = array[i];
        array[i] = array[half - i - 1];
        array[half - i - 1] = temp;
    }   

    for(int i = 0; i < (half / 2); i++){
        int temp = array[half + i];
        array[half + i] = array[size - half - i - 1];
        array[size - half - i - 1] = temp;
    }

    for(int i = 0; i < (half / 2); i++){
        int temp = array[half * 2 + i];
        array[half * 2 + i] = array[size - i - 1];
        array[size - i - 1] = temp;
    } 
         
}

int main(){
    const int SIZE = 12;
    int array[SIZE];

    if(initArray(array, SIZE)) abort();

    reverseArray(array, SIZE);   
    
    printArray(array, SIZE);

    return 0;
}