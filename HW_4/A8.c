#include <stdio.h>
#include <stdlib.h>

/*
    Наибольшее из трех чисел
    Ввести три числа и найти наибольшее из них

    Формат входных данных
    Три целых числа через пробел

    Формат результата
    Одно наибольшее целое число
*/

int main()
{
    int a, b, c, max;
    int result = scanf("%d%d%d", &a, &b, &c);
    if(result != 3) abort();

    max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    printf("%d\n", max);
    return 0;
}
