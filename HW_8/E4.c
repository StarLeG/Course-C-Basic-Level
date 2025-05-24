#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
                         Два максимума
    Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.

    Формат входных данных
    10 целых чисел через пробел.

    Формат результата
    Сумма двух максимальных элементов.
*/

bool initArray(int *array, const int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1) return true;
        array[i] = n;
    }

    return false;
}

int maxTwoSum(const int* array, const int size){

    int max1 = INT_MIN;
    int max2 = max1;
    int idx_Max1 = 0;    

    for(int i = 0; i < size; i++){
        if(array[i] > max1){
            idx_Max1 = i;
            max1 = array[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if(idx_Max1 == i) continue;
        if(array[i] > max2){            
            max2 = array[i];
        }
    } 

    return max1 + max2;

}

int main(){

    #define SIZE 10
    int array[SIZE] = {0};

    if(initArray(array, SIZE)) abort();

    printf("%d\n", maxTwoSum(array, SIZE));

    return 0;
}