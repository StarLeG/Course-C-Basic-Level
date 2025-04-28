#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Сумма цифр равна произведению
    Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению.
    int is_happy_number(int n)

    Формат входных данных
    Целое не отрицательное число

    Формат результата
    YES или NO
*/

int is_happy_number(int n);

int main(){
    int n;
    int result = scanf("%u", &n);
    if(result != 1 || n < 0) abort();

    is_happy_number(n) ? printf("YES\n") : printf("NO\n");

    return 0;
}

int is_happy_number(int n){

    int sum = 0;
    int mul = 1;

    while (n != 0)
    {
        sum += n % 10;
        mul *= n % 10;
        n /= 10;
    }

    return sum == mul ? true : false;
    
}