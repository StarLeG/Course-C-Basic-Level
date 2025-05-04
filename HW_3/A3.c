#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
   int result = scanf("%d%d%d", &a, &b, &c);

   if(result != 3) abort();

    printf("%d+%d+%d=%d\n", a, b, c, a + b + c);
    return 0;
}