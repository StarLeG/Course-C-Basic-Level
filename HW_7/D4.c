#include <stdio.h>
#include <stdlib.h>

/*
В прямом порядке
    Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке,
    разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.
    void print_num(int num)

    Формат входных данных
    Одно целое неотрицательное число
    
    Формат результата
    Все цифры числа через пробел в прямом порядке
*/

void print_num(int num);

int main(){
    int x;
    int result = scanf("%u", &x);
    if(result != 1) abort();

    print_num(x);

    return 0;
}

void print_num(int num)
{
    if (num < 10) {
        printf("%d", num);
    } else {
        print_num(num / 10);
        printf(" %d", num % 10);
    }
}