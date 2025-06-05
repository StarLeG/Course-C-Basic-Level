/*
    Поменять местами
    Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
    Прототип функции void change_max_min(int size, int a[])

    Формат входных данных
    Функция принимает на вход размер массива и массив чисел типа int

    Формат результата
    Функция не возвращает значения, измененный массив сохраняется на месте исходного.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1000

void change_max_min(int size, int a[]){
    int min = INT_MAX;
    int max = INT_MIN;
    int idx_min = -1;
    int idx_max = -1;

    for(int *p = a; p < a + size; p++){
        if(*p < min){
            min = *p;
            idx_min = p - a;
        }

        if(*p > max){
            max = *p;
            idx_max = p - a;
        }

    }

    //printf("%d %d\n", idx_min, idx_max);
    //printf("%d %d\n", a[idx_min], a[idx_max]);

    int tmp = a[idx_min];
    a[idx_min] = a[idx_max];
    a[idx_max] = tmp;

}


int main(){
    int array[SIZE];
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++){
        array[i] = rand() % INT_MAX;
    }

    change_max_min(SIZE, array);

    getchar();

    return 0;
}
    