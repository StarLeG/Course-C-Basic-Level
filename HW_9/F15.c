/*
    Больше по модулю
    Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел,
    сколько элементов превосходят по модулю максимальный элемент.
    Прототип функции int count_bigger_abs(int n, int a[]);

    Формат входных данных
    Функция получает размер массива и массив целых чисел

    Формат результата
    Функция возвращает целое число раное количеству элементов превосходящих по модулю максимальный элемент.
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

int count_bigger_abs(int n, int a[]){

    int max = INT_MIN;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(max < a[i]) max = a[i];
    }

    for(int i = 0; i < n; i++){
        if(max < abs(a[i])) cnt++;
    }

    return cnt;
}

int main(){
    int array[] = {1, -20, 3, 4, -50, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    
    printf("%d\n", count_bigger_abs(size, array));

    getchar();

    return 0;
}