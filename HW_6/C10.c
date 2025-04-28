#include <stdio.h>
#include <stdlib.h>

// Составить функцию,
// печать всех простых множителей числа.
// Использовать ее для печати всех простых множителей числа.
// Составить функцию, печать всех простых множителей числа. 
// Использовать ее для печати всех простых множителей числа. void print_simple(int n)

void print_simple(int n);

int main(){
    int n;

    scanf("%d", &n);

    if(n < 2) abort();

    print_simple(n);

    return 0;
}

void print_simple(int n){

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


}