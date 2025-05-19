#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                Отсортировать по последней цифре
    Считать массив из 10 элементов и отсортировать его по последней цифре.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    Этот же массив отсортированный по последней цифре

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

void BubbleSortLastDigit(int *array, const int size){
    int tmp;
    bool noSwap;

    for (int i = size - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (array[j] % 10 > array[j + 1] % 10)
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }
}

int main(){
    const int SIZE = 10;
    int array[SIZE];

    if(initArray(array, SIZE)) abort();

    BubbleSortLastDigit(array, SIZE);

    printArray(array, SIZE);

    return 0;
}