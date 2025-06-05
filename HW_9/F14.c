/*
                Cумма в интервале
    Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
    Прототип функции int sum_between_ab(int from, int to, int size, int a[])

    Формат входных данных
    Функция принимает концы отрезка from и to, размер массива, массив целых чисел

    Формат результата
    Функция возвращает сумму элементов в интервале [from, to]
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1000

int sum_between_ab(int from, int to, int size, int a[]){
    int sum = 0;   

    for(int *p = a; p < a + size; p++){
        if(p - a >= from && p - a <= to){
            sum += *p;
        }
    }
    return sum;
}

int main(){
    int array[SIZE];
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++){
        array[i] = rand() % INT_MAX;
    }

    int a[] = {4, 6, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(a) / sizeof(a[0]);

    printf("%d\n", sum_between_ab(5, 7, size, a));

   //printf("%d\n", sum_between_ab(5, 13, SIZE, array));

    getchar();

    return 0;
}