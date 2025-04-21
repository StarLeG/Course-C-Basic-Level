#include <stdio.h>

int main()
{
    int a, b;
    int value = 0;
    scanf("%d %d", &a, &b);

    if(a == b){
        value = 3;
    }else
        value = (a > b) ?  1 :  2;

    switch (value) {
    case 1:
        printf("Above\n");
        break;
    case 2:
        printf("Less\n");
        break;
    case 3:
        printf("Equal\n");
        break;
    default:
        break;
    }

    return 0;
}
