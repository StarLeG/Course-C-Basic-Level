#include <stdio.h>
#include <stdlib.h>

/*
                    Уравнение прямой
    Определить уравнение прямой по координатам двух точек. Уравнение вида

    y=k*x+b
    Формат входных данных
    Четыре целых числа через пробел. Координаты X1 Y1 X2 Y2

    Формат результата
    Два числа K,B в формате "%.2f %.2f"
*/

int main()
{
    int x1, y1, x2, y2;
    double k, b;

    int result = scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if(result != 4) abort();

    k = ((double)y2 - (double)y1) / ((double)x2 - (double)x1);
    b = (double)y1 - (k * (double)x1);

    printf("%.2f %.2f\n", k, b);
    return 0;
}
