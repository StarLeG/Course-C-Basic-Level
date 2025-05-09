#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/*
                            В двоичную систему
    Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.

    Формат входных данных
    Целое не отрицательное число в десятичной системе счисления
    Формат результата
    Целое число в двоичной системе счисления
*/

int dec_to_bin(uint32_t numDec);

int main() {
    uint32_t num;
    if (scanf("%" SCNu32, &num) != 1) abort();

    printf("%d", dec_to_bin(num));

    return 0;
}

int dec_to_bin(uint32_t numDec) {
    if (numDec == 0) {
        return 0;
    } else {
        return dec_to_bin(numDec / 2) * 10 + (numDec % 2);
    }
}