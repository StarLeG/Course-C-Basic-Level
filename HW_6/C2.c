#include <stdio.h>

// Составить функцию, возведение числа N в степень P.
// int power(n, p) и привести пример ее использования.

int power(int n, int p);

int main(){
    int n, p;

    scanf("%d %d", &n, &p);

    printf("%d\n", power(n, p));

    return 0;
}

int power(int n, int p){
    int pow = n;
    for(int i = 1; i < p; i++){
        pow *= n;
    }
    
    if(p == 0) return 1;

    return pow;
}