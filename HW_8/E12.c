#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    По убыванию и по возрастанию
    Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.
*/

bool initArray(int *array, const int size){
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

void splitSort(int *array, const int size){
    int tmp;
    bool noSwap;

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
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

    for (int i = size / 2 ; i < size ; i++)
    {
        noSwap = 1;
        for (int j = size / 2; j < size; j++)
        {
            if(j + 1 == 10) break;
            if (array[j] < array[j + 1])
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
    #define SIZE 10
    int array[SIZE] = {0};

    if(initArray(array, SIZE)) abort();

    splitSort(array, SIZE);

    printArray(array, SIZE);

    return 0;
}