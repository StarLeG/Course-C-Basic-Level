#include <stdio.h>
#include <stdlib.h>

/*
    Сумма цифр числа
    Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
    int sum_digits(int n)

    Формат входных данных
    Одно натуральное число.
    Формат результата
    Целое число - сумма цифр введенного числа.
*/

int sum_digits(int n);

int main(){

    int n;

    if(scanf("%d", &n) != 1) abort();

    printf("%d\n", sum_digits(n));

    return 0;
}

 int sum_digits(int n){

    static int sum = 0;
    sum += n % 10;
    n /= 10;
    if(n > 0){
        sum_digits(n);
    }else  
        return sum;    

 }