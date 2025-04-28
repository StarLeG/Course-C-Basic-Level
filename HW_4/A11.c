#include <stdio.h>

int main()
{
    int a, b, c, d, e, min, max;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

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
