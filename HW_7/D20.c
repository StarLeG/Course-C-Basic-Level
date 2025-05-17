#include <stdio.h>
#include <stdlib.h>

/*
    Возвести в степень
    Написать рекурсивную функцию возведения целого числа n в степень p.
    int recurs_power(int n, int p)
    Используя данную функцию, решить задачу.

    Формат входных данных
    Два целых числа -100 ≤ n ≤ 100 и 0 ≤ p ≤ 100

    Формат результата
    Одно целое число n в степени p
*/

int recurs_power(int n, int p){
    if (p == 0) return 1;
    if (p == 1) return n;
    return n * recurs_power(n, p - 1);
}

int main(){
    int n, p;
    if(scanf("%d%d", &n, &p) != 2 || n < -100 || n > 100 || p < 0 || p > 100) abort();

    printf("%d\n", recurs_power(n, p));

    return 0;
}