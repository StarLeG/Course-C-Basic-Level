#include <stdio.h>

// На вход подается произвольное трехзначное число, напечать сумму цифр

int main()
{
    int a, sum;
    int firstNumb;
    int secondNumb;
    int thirdNumb;

    scanf("%d", &a);

    firstNumb = a / 100;
    secondNumb = (a - (firstNumb * 100)) / 10;
    thirdNumb = a - (firstNumb * 100) - (secondNumb * 10);

    sum = firstNumb + secondNumb + thirdNumb;

    printf("%d\n", sum);
    return 0;
}
