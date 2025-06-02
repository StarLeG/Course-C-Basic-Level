#include <stdio.h>
#include <stdlib.h>

/*
    Упаковать 0 и 1
    Написать функцию, которая сжимает серии массива,
    состоящего из единиц и нулей по следующему принципу:
    например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1]
    преобразуется в [4,7,2,4]
    (т.к. начинается с нуля, то сразу записывается количество элементов первой серии);
    а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7]
    (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).


    Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции:
     int compression(int a[], int b[], int N)

    Формат входных данных
    Функция принимает исходный массив a[] и сжимает в массив b[], N - число элементов в массиве a[].

    Формат результата
    Функция возвращает число элементов сжатого массива b[]
*/

int compression(int a[], int b[], int N){
    if (N == 0) return 0;

    int current = a[0];
    int count = 1;
    int index = 0;

    if (current == 1) {
        b[index++] = 0;
    }

    for (int i = 1; i < N; i++) {
        if (a[i] == current) {
            count++;
        } else {
            b[index++] = count;
            current = a[i];
            count = 1;
        }
    }

    b[index++] = count;
    
    return index;
}

int main(){

    int array1[] = {0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1};
    int size = sizeof(array1) / sizeof(array1[0]);
    int array2[size];

    for (int *p = array2; p < array2 + size; p++)
    {
        *p = 0;
    }

    int size2 = compression(array1, array2, size);

    for(int i = 0; i < size2; i++){
        printf("%d ", array2[i]);
    }
    
    
    printf("\n");   
  
    system("pause");
    return 0;
}