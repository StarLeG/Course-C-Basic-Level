#include <stdio.h>
#include <stdlib.h>

/*
                Максимальная цифра
    Дано трехзначное число, напечатать макисмальную цифру

    Формат входных данных
    Целое положительное трехзначное число

    Формат результата
    Одна цифр
*/

int main()
{
    int a, max;
    int firstNumb;
    int secondNumb;
    int thirdNumb;

    int result = scanf("%d", &a);
    if(result != 1) abort();

    firstNumb = a / 100;
    secondNumb = (a - (firstNumb * 100)) / 10;
    thirdNumb = a - (firstNumb * 100) - (secondNumb * 10);

    max = firstNumb;
    if(max < secondNumb) max = secondNumb;
    if(max <thirdNumb) max = thirdNumb;

    printf("%d\n", max);
    return 0;
}
