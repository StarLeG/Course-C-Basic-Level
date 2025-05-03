#include <stdio.h>

/*
                            Сумма чисел от 1 до N
    Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N

    Формат входных данных
    Одно натуральное число

    Формат результата
    Сумма чисел от 1 до введенного числа
*/

int printSumNumber(int numb);

int main(){
    int x;
    int result = scanf("%d", &x);
    if(result != 1) return 1;

    printf("%d\n", printSumNumber(x));
    
    return 0;
}

int printSumNumber(int numb){
    if (numb <= 0) {  
        return 0;
    }
    if (numb == 1) {  
        return 1;
    }
    return numb + printSumNumber(numb - 1);      
    
}