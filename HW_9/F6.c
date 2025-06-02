#include <stdio.h>
#include <stdbool.h>

/*
    Два одинаковых
    Написать только одну логическую функцию, которая определяет, верно ли,
    что среди элементов массива есть два одинаковых.
    Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
    int is_two_same(int size, int a[]);

    Формат входных данных
    Массив из целых чисел

    Формат результата
    Функция возвращает 1 или 0
*/

void BubbleSort(int *array, const int size){
    int tmp;
    bool noSwap;

    for (int i = size - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }
}

int is_two_same(int size, int a[]){
    BubbleSort(a, size);
    int isTwoSame = 0;

    for(int *p = a; p < a + size; p++){
        if(*p == *(p + 1)){
            isTwoSame = 1;
            break;
        } 
    }

    return isTwoSame;
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
                 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
                 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
                 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94,
                 95, 96, 97, 98, 99, 100};

    int size = sizeof(array) / sizeof(array[0]);

    if(is_two_same(size, array)){
        printf("YES\n");
    }else{
        printf("NO\n");
    } 
}