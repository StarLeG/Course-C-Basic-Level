#include <stdio.h>

int main()
{
    int x1, y1, x2, y2;
    double k, b;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    k = ((double)y2 - (double)y1) / ((double)x2 - (double)x1);
    b = (double)y1 - (k * (double)x1);

    printf("%.2f %.2f\n", k, b);
    return 0;
}
