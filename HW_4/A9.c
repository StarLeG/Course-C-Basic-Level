#include <stdio.h>
#include <stdlib.h>

/*
    Наибольшее из пяти чисел
    Ввести пять чисел и найти наибольшее из них.

    Формат входных данных
    Пять целых чисел разделенных пробелом

    Формат результата
    Одно целое число
*/

int main()
{
    int a, b, c, d, e, max;
    int result = scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    if(result != 5) abort();

    max = a;
    if(max < b) max = b;
    if(max < c) max = c;
    if(max < d) max = d;
    if(max < e) max = e;
    
    printf("%d\n", max);
    return 0;
}
