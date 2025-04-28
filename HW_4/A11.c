#include <stdio.h>
#include <stdlib.h>

/*
    Сумма максимума и минимума
    Напечатать сумму максимума и минимума.

    Формат входных данных
    Пять целых чисел через пробел

    Формат результата
    Одно целое число - сумма максимума и минимума
*/

int main()
{
    int a, b, c, d, e, min, max;

    int result = scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    if(result != 5) abort();

    min =  a;
    max = a;

    if(min > b) min = b;
    if(min > c) min = c;
    if(min > d) min = d;
    if(min > e) min = e;

    if(max < b) max = b;
    if(max < c) max = c;
    if(max < d) max = d;
    if(max < e) max = e;

    printf("%d\n", min + max);

    return 0;
}
