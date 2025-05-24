#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                        Максимум и минимум
    Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
*/

bool initArray(int *array, const int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1) return true;
        array[i] = n;
    }

    return false;
}

void find_Min_Max(int *array,
                 int size,
                 int *idx_Max,
                 int *max,
                 int *idx_Min,
                 int *min){

    *idx_Min = 1;
    *idx_Max = 1;
    *min = array[0];
    *max = array[0];             

    for(int i = 1; i < size; i++){
        if(array[i] < *min){
            *min = array[i];
            *idx_Min = i + 1;
        }

        if(array[i] > *max){
            *max = array[i];
            *idx_Max = i + 1;
        }
    }

}

int main(){
    int idx_Max, idx_Min, min, max;

    #define SIZE  10
    int array[SIZE] = {0};

    if(initArray(array, SIZE)) abort();

    find_Min_Max(array, SIZE, &idx_Max, &max, &idx_Min, &min);

    printf("%d %d %d %d\n", idx_Max, max, idx_Min, min);
  
    return 0;    
}