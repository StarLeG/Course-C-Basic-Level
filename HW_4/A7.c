#include <stdio.h>
#include <stdlib.h>

/*
    Наибольшее из двух чисел
    Ввести два числа и вывести их в порядке возрастания.

    Формат входных данных
    Два целых числа

    Формат результата
    Два целых числа
*/

int main()
{
    int a, b;
    int result = scanf("%d%d", &a, &b);
    if(result != 2) abort();

    a > b ? printf("%d %d", b, a) : printf("%d %d", a, b);

    return 0;
}
