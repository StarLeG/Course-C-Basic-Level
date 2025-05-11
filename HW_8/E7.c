#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                             Инверсия половинок
    Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива.
    Необходимо изменить считанный массив и напечатать его одним циклом.

    Формат входных данных
    10 целых элементов массива через пробел.

    Формат результата
    10 целых элементов массива через пробел.
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

    
    int half = size / 2;
    for(int i = 0; i < half / 2; i++){
        int temp = array[i];
        array[i] = array[half - i - 1];
        array[half - i - 1] = temp;
    }   
    
     for(int i = 0; i < (size - half) / 2; i++){
        int temp = array[half + i];
        array[half + i] = array[size - i - 1];
        array[size - i - 1] = temp;
    } 
    
}



int main(){
    const int SIZE = 10;
    int array[SIZE];

    if(initArray(array, SIZE)) abort();

    reverseArray(array, SIZE);   
    
    printArray(array, SIZE);

    return 0;
}