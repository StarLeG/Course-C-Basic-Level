#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    int result = scanf("%d%d", &a, &b);
    if(result != 2) abort();

    printf("%d\n", a - b);

    return 0;
}