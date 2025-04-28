#include <stdio.h>
#include <stdlib.h>

/*
    Наименьшее из пяти чисел
    Ввести пять чисел и найти  наименьшее из них.

    Формат входных данных
    Пять целых чисел

    Формат результата
    Одно целое число
*/

int main()
{
    int a, b, c, d, e, min;
    int result = scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    if(result != 5) abort();

    min = a;
    if(min > b) min = b;
    if(min > c) min = c;
    if(min > d) min = d;
    if(min > e) min = e;
    
    printf("%d\n", min);
    return 0;
}
