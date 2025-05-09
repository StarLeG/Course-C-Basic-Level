#include <stdio.h>
#include <stdlib.h>

/*
                    Проверка на простоту
    Дано натуральное число n ≥ 1. Проверьте, является ли оно простым.
    Программа должна вывести слово YES, если число простое или NO в противном случае.
    Необходимо составить рекурсивную функцию и использовать ее.
    int is_prime(int n, int delitel)

    Формат входных данных
    Натуральное число

    Формат результата
    YES или NO
*/

int is_prime(int n, int delitel);

int main(){

    int n;
    if(scanf("%d", &n) != 1 || n < 1) abort();

    if (n == 1) {
        printf("NO\n");
    } else if (n == 2) {
        printf("YES\n");
    } else {
        printf(is_prime(n, 2) ? "YES\n" : "NO\n");
    }

    return 0;
}

int is_prime(int n, int delitel){
     if (delitel * delitel > n) {
        return 1;
    }
    if (n % delitel == 0) {
        return 0;
    }
    return is_prime(n, delitel + 1);
}