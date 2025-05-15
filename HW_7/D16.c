#include <stdio.h>
#include <stdlib.h>

/*
    Точная степень двойки
    Написать логическую рекурсивную функцию и используя ее определить
    является ли введенное натуральное число точной степенью двойки.
    int is2pow(int n)

    Формат входных данных
    Одно натуральное число.

    Формат результата
    YES или NO
*/

int is2pow(int n){
    
    if( n == 1) return 1;
    if(n % 2 != 0) return 0;

    return is2pow(n / 2);

}

int main(){
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) abort(); 

    is2pow(n) ? printf("YES\n") : printf("NO\n");

    return 0;
}