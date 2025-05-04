#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    int result = scanf("%d%d%d", &a, &b, &c);
    if(result != 3) abort();
    printf("%.2f", ((double)a + (double)b + (double)c) / 3.);
    return 0;
}
