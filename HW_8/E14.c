#include <stdio.h>
#include <stdbool.h>
#include <stdlib>

/*
                Более одного раза
    Считать массив из 10 элементов и выделить в другой массив все числа,
    которые встречаются более одного раза.
    В результирующем массиве эти числа не должны повторяться.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    Целые числа через пробел, которые встречаются более одного раза в исходном массиве.
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
    int array1[SIZE];
    int array2[SIZE];
    int cnt = -1;

    if(initArray(array1, SIZE)) abort();
    
    

    if(cnt == -1) return 0;

    printArray(array2, cnt + 1);

    return 0;
}