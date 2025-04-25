#include <stdio.h>

// Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.

int sum(int n);

int main(){
    int n;

    scanf("%d", &n);

    printf("%d\n", sum(n));

    return 0;
}

int sum(int n){
    int sum = 0;

    for(int i = 1; i <= n; i++){
        sum += i;
    }

    return sum;
}