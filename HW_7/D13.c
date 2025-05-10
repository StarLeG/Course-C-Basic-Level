#include <stdio.h>
#include <stdlib.h>

/*
                         Печать простых множителей
    Составить рекурсивную функцию, печать всех простых множителей числа.

    Формат входных данных
    Натуральное число

    Формат результата
    Последовательность из всех простых делителей числа через пробел
*/

void printPrimeFactors(int n);

int main(){
    int n;
    if(scanf("%d", &n) != 1 || n < 1) abort();

    printPrimeFactors(n);

    return 0;
}

void printPrimeFactors(int n){
    if(n < 2) return;

    while (n % 2 == 0) {
        printf("%d ", 2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

     if (n > 2) {
        printf("%d ", n);
    }

    printf("\n");

}