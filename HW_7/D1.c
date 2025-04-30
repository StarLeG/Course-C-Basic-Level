#include <stdio.h>

/*
                        От 1 до N
    Составить рекурсивную функцию, печать всех чисел от 1 до N

    Формат входных данных
    Одно натуральное число

    Формат результата
    Последовательность чисел от 1 до введенного числа
*/

void printNumber(int numb);

int main(){
    int x;
    int result = scanf("%d", &x);
    if(result != 1) return 1;

    printNumber(x);
    printf("\n");

    return 0;
}

void printNumber(int numb){

    if (numb > 1){
        printNumber(numb - 1);
    }
    
    printf("%d ", numb);
}