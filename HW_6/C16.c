#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                        Проверка на простоту
    Составить функцию логическую функцию, которая определяет, верно ли, что число простое.
    Используя функцию решить задачу. int is_prime(int n)

    Формат входных данных
    Одно целое не отрицательное число.

    Формат результата
    YES или NO
*/

int is_prime(int n);

int main(){
    int n;
    int result = scanf("%u", &n);
    if(result != 1 || n < 0) abort();

    is_prime(n) ? printf("YES\n") : printf("NO\n");

    return 0;
}

int is_prime(int n){
    if (n <= 1) {
        return false;  
    }
    if (n == 2) {
        return true;   
    }
    if (n % 2 == 0) {
        return false;  
    }    
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}