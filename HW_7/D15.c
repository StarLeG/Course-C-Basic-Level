#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
                    Найти наибольшее
    Дана последовательность ненулевых целых чисел, завершающаяся числом 0.
    Ноль в последовательность не входит. Определите наибольшее значение числа в этой последовательности.
    Для решения задачи необходимо написать рекурсивную функцию вида:
    int max_find(int max)

    Формат входных данных
    Последовательность не нулевых целых чисел. В конце последовательности число 0.

    Формат результата
    Одно число. Максимум последовательности.
*/

int max_find(int max);

int main(){

    printf("%d\n", max_find(INT_MIN));

    return 0;
}

int max_find(int max){
    int num;
    if(scanf("%d", &num) != 1) abort();
    
    if (num == 0) {
        return max;
    }
    
    if (num > max) {
        return max_find(num);
    } else {
        return max_find(max);
    }

}