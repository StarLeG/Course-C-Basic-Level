/*
    Сумма минимальна
    Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int.
    Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива,
    сумма которых минимальна.

    Формат входных данных
    Последовательность из 30 целых чисел через пробел
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 30

void printMinSumPair(const int array[], const int size){
    if(size == 0) return;
    int sum = INT_MAX;
    int idx_1 = -1;
    int idx_2 = -1;

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            int res = array[i] + array[j]; 
            if(sum > res){
                sum = array[i] + array[j];
                idx_1 = i;
                idx_2 = j;
            }
        }
        
    }

    printf("%d %d\n", idx_1, idx_2);
}

int main(){
    int array[SIZE] = {0};
    int num;

    for(int *p = array; p < array + SIZE; p++){
        if(scanf("%d", &num) != 1) abort();
        *p = num;
    }

    printMinSumPair(array, SIZE);

    system("pause");

    return 0;
}