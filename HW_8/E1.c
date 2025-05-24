#include <stdio.h>
#include <stdlib.h>


/*
                        Среднее арифметическое чисел
    Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

    Формат входных данных
    5 целых не нулевых чисел через пробел

    Формат результата
    Одно число в формате "%.3f"
*/

double avg(int *array, const int size);

int main(){

    #define SIZE 5
    int array[SIZE] = {0};
    int n;

    for(int i = 0; i < SIZE; i++){
        if(scanf("%d", &n) != 1) abort();
        array[i] = n;
    }

    printf("%.3f\n", avg(array, sizeof(array) / sizeof(array[0])));    

    return 0;
}

double avg(int *array, const int size){

    double retVal = 0.f;

    for (int i = 0; i < size; i++)
    {
        retVal += array[i]; 
    }
    
    return retVal / size;
}