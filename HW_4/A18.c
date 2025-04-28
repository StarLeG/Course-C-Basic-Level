#include <stdio.h>
#include <stdlib.h>

/*
                    Above, less, equal
    Ввести два числа. Если первое число больше второго, то программа печатает слово Above.
    Если первое число меньше второго, то программа печатает слово Less. А если числа равны,
    программа напечатает сообщение Equal.

    Формат входных данных
    Два целых числа

    Формат результата
    Одно единственное слово: Above, Less, Equal
*/

int main()
{
    int a, b;
    int value = 0;
    int result = scanf("%d %d", &a, &b);
    if(result != 2) abort();

    if(a == b){
        value = 3;
    }else
        value = (a > b) ?  1 :  2;

    switch (value) {
    case 1:
        printf("Above\n");
        break;
    case 2:
        printf("Less\n");
        break;
    case 3:
        printf("Equal\n");
        break;
    default:
        break;
    }

    return 0;
}
