#include <stdio.h>
#include <stdlib.h>

/*
                        Функция Аккермана
    Функция Аккермана определяется рекурсивно для неотрицательных целых чисел m и n следующим образом:

    A(0, m) = m + 1;
    A(n + 1, 0) = A(n, 1);
    A(n + 1, m + 1) = A(n, A(n + 1, m))

    Реализуйте данную функцию по прототипу
    int akkerman(int m, int n)

    Формат входных данных
    Даны неотрицательные целые числа m и n

    Формат результата
    Одно целое число
*/

int akkerman(int m, int n){
     if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return akkerman(m - 1, 1);
    } else {
        return akkerman(m - 1, akkerman(m, n - 1));
    }
}

int main(){
    int m, n;
    if(scanf("%d%d", &m, &n) != 2 || m < 0 || n < 0) abort();
    printf("%d\n", akkerman(m, n));

    return 0;
}