#include <stdio.h>
#include <stdlib.h>

/*
                        Существует ли треугольник
    Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.

    Формат входных данных
    Три целых числа. Стороны треугольника a, b, c.

    Формат результата
    YES или NO
*/

int main()
{
    int a, b, c;
    int result = scanf("%d %d %d", &a, &b, &c);
    if(result != 3) abort();

    if(a + b > c && a + c > b && b + c > a){
        printf("YES\n");
    }else
        printf("NO\n");
    return 0;
}
