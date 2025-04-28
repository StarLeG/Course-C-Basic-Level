#include <stdio.h>

int main()
{
    int a, max;
    int firstNumb;
    int secondNumb;
    int thirdNumb;

    scanf("%d", &a);

    firstNumb = a / 100;
    secondNumb = (a - (firstNumb * 100)) / 10;
    thirdNumb = a - (firstNumb * 100) - (secondNumb * 10);

    max = firstNumb;
    if(max < secondNumb) max = secondNumb;
    if(max <thirdNumb) max = thirdNumb;

    printf("%d\n", max);
    return 0;
}
