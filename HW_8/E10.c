#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
        Циклический сдвиг массива вправо на 4
    Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.

    Формат входных данных
    12 целых чисел через пробел

    Формат результата
    12 целых чисел через пробел
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

void reverse(int *array, int begin, int end){
    while (begin < end)
    {
        int tmp = array[begin];
        array[begin] = array[end];
        array[end] = tmp;
        begin++;
        end--;
    }
    
}

void arrayRotateRight(int *array, int size, int shift){
    shift %= size;
    reverse(array, 0, size - 1);  // переворачиваем весь массив
    reverse(array, 0, shift - 1); // переворачиваем первые shift элементы
    reverse(array, shift, size - 1); // переворачиваем оставшиеся элементы
}

int main(){
    #define SIZE 12
    int array[SIZE] = {0};

    if(initArray(array, SIZE)) abort();

    arrayRotateRight(array, SIZE, 4);  
    
    printArray(array, SIZE);

    return 0;
}