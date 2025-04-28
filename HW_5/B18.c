#include <stdio.h>

// Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
// Числа Фибоначчи – это элементы числовой последовательности
//  1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …,
//  в которой каждое последующее число равно сумме двух предыдущих.

int main(){
    int n, fib;
    int fib1 = 1;
    int fib2 = 1;

    scanf("%d", &n);

    if(n < 1) return 1;

    if(n >= 1) printf("%d ", fib1);
    if(n >= 2) printf("%d ", fib2);

    for(int i = 3; i <= n; i++){
        fib = fib1 + fib2;
        printf("%d ", fib);
        fib1 = fib2;
        fib2 = fib;        
    }

    printf("\n");

    return 0;
}