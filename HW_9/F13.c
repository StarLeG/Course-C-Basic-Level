#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
                    В заданном интервале
    Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
    Прототип функции
        int count_between(int from, int to, int size, int a[])

    Формат входных данных
    Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.

    Формат результата
    Функция возвращает целое число - количество числе в интервале [from, to]
*/

#define MAX_RAND 101
#define SIZE 100

int count_between(int x, int to, int size, int a[]){
    if (x > to) return 0;
    int count = 0;    
    int *end = a + size; 
    for (int *p = a; p < end; p++) {
        if (*p >= x && *p <= to) {
            count++;
        }
    }
    return count;
}

int main(){

    srand(time(NULL));
    int result = 0;

    int array[SIZE]= {0};
    
    for(int i = 0; i < 100; i++){
        array[i] = rand() % MAX_RAND;
    }

    result = count_between(1, 2, SIZE, array);

    printf("%d\n", result);

     getchar();

    return 0;
}