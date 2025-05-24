#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                Среднее арифметическое массива
    Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.

    Формат входных данных
    12 целых чисел через пробел

    Формат результата
    Среднее арифметическое в формате "%.2f"
*/

bool initArray(int *array, const int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1) return true;
        array[i] = n;
    }

    return false;
}

double avg(const int *array, const int size){

    double retVal = 0.f;

    for (int i = 0; i < size; i++)
    {
        retVal += array[i]; 
    }
    
    return retVal / size;
}

int main(){

    #define SIZE  12
    int array[SIZE];

    if(initArray(array, SIZE)) abort();

    printf("%.2f", avg(array, SIZE));

    return 0;
}
