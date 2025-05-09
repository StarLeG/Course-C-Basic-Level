#include <stdio.h>
#include <stdlib.h>

/*
                    От 1 до N
    Составить рекурсивную функцию, печать всех чисел от N до 1.

    Формат входных данных
    Одно натуральное число

    Формат результата
    Последовательность целых чисел от введенного числа до 1, через пробел.

*/

void revPrintNumb(int n);

int main(){
    int numb;
    if(scanf("%d", &numb) != 1) abort();
    revPrintNumb(numb);
    return 0;
}

void revPrintNumb(int n){
    
    if(n > 0){        
        printf("%d ", n);
        revPrintNumb(--n);
    }else
        return;

}