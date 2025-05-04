#include <stdio.h>
#include <stdlib.h>

// На вход подается произвольное трехзначное число, напечать произведение цифр

int main()
{
    int a, mul;
    int firstNumb;
    int secondNumb;
    int thirdNumb;

    int result = scanf("%d", &a);
    if (result != 1) abort();

    firstNumb = a / 100;
    secondNumb = (a - (firstNumb * 100)) / 10;
    thirdNumb = a - (firstNumb * 100) - (secondNumb * 10);

    mul = firstNumb * secondNumb * thirdNumb;

    printf("%d\n", mul);
    return 0;
}
