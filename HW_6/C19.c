#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Сумма цифр в тексте
    Составить функцию, которая преобразует текущий символ цифры в число.
    Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)

    Формат входных данных
    Строка состоящая из английских букв, пробелов, знаков препинания. В конце строки символ точка.

    Формат результата
    Целое число - сумма цифр в тексте
*/

int digit_to_num(char c);

int main(){
    char ch;
    int sum = 0;

    do{
        ch = getchar();
        sum += (ch - '0') * digit_to_num(ch);

    }while(ch != '.');

    printf("%d\n", sum);

    return 0;
}

int digit_to_num(char c){

    if(c >= '0' && c <= '9') return true;

    return false;
}