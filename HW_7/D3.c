#include <stdio.h>
#include <stdlib.h>

/*
                    В обратном порядке
    Дано целое не отрицательное число N. Выведите все его цифры по одной,
    в обратном порядке, разделяя их пробелами или новыми строками.

    Формат входных данных
    Одно не отрицательное целое число

    Формат результата
    Последовательность цифр введенного числа в обратном порядке через пробел
*/

void printDigits(int x);

int main(){
    int x;

    int result = scanf("%u", &x);
    if(result != 1) abort();

    printDigits(x);

    return 0;
}

void printDigits(int x){
    if (x < 0) abort();
    
    if (x < 10) {
        printf("%d ", x);
    } else {
        printf("%d ", x % 10);
        printDigits(x / 10);
    }
}