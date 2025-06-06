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
#include <stdlib.h>

int sum_between_ab(int from, int to, int size, int a[]){
    int sum = 0;     
    #if 1
        for(int *p =a; p < a + size; p++){    
            if(*p >= from && *p <= to){        
                sum += *p;
            }
        }
    #endif

    #if 0
        for(int *p =a + size - 1; p >= a; p--){    
            if(*p >= from && *p <= to){        
                sum += *p;
            }
        }
    #endif


    return sum;
}

int main(){
    
    int from, to;
    
    scanf("%d%d", &from, &to);

    //int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[] = {11, 25, 5, -48, -15, -16, 27, 43, -22, -1 };

    int size = sizeof(a) / sizeof(a[0]);

    printf("%d\n", sum_between_ab(from, to, size, a));  

    system("pause");

    return 0;
}