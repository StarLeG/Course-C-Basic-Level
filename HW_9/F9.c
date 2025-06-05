#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>


#define SIZE 100

/*
                            Поменять местами
    Составить только функцию которая в массиве находит максимальный из отрицательных элементов
    и меняет его местами с последним элементом массива.
    Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует.
    Если отрицательных элементов нет - массив не менять.
    Прототип функции: void swap_negmax_last(int size, int a[])

    Формат входных данных
    Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел.
*/



void swap_negmax_last(int size, int a[]){

    int min = INT_MIN;
    int idx = -1;
    

    for(int *p = a; p < a + size; p++){
        if(min < *p && *p < 0){
            min = *p;
            idx = p - a;            
        } 
    }   

    if(idx == -1) return;

    int *pLast = a + size - 1; 
    int *pMin = a + idx;   
    int tmp = *pMin;
    *pMin= *pLast;
    *pLast = tmp;

}

 int main(){
    int array[SIZE] = {0};

    srand(time(NULL));

    for(int *p = array; p < array + SIZE; p++){
        *p = rand() % 201 - 100;
    }

    for(int *p = array; p < array + SIZE; p++){
        printf("%d ", *p);
    }

    printf("\n\n\n");

    swap_negmax_last(SIZE, array);

    for(int *p = array; p < array + SIZE; p++){
        printf("%d ", *p);
    }

    printf("\n\n\n");

    int a[] = {1, -2, -3, -4, 5, 6, 7, 8, 9, 10};
    for(int *p = a; p < a + 10; p++){
        printf("%d ", *p);
    }
    swap_negmax_last(10, a);

    printf("\n\n\n");

    for(int *p = a; p < a + 10; p++){
        printf("%d ", *p);
    }

    getchar();
    return 0;
} 
 