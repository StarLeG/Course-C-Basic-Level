#include <stdio.h>
#include <stdlib.h>

// Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n) 

int factorial(int n); 

int main(){

    int n;

    scanf("%d", &n);

    if(n < 0 || n > 20) abort();

    printf("%d\n", factorial(n));

    return 0;
}

int factorial(int n) {

    int fac = 1;

    for(int i = 1; i <= n; i++){
        fac *= i;
    }

    return fac;

}