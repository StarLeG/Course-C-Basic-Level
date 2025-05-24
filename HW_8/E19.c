#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
            Цифры по порядку
    Вывести в порядке следования цифры,
    входящие в десятичную запись натурального числа N.

    Формат входных данных
    Одно натуральное число N

    Формат результата
    Цифры через пробел
*/

//#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int countDigit(int num){
    if(num == 0) return 1;

    int cnt = 0;

    while (num != 0)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}

void printArray(const int* array, const int size){    

    for(int i = size - 1; i >= 0; i--){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void splitNumberIntoDigits(int number, int array[]){
    if(number == 0){
        array[0] = 0;
        return;
    }

    int idx = 0;

    while (number > 0)
    {
        array[idx] = number % 10;
        number /= 10;
        idx++;
    }
    
}

int main(){
    int number = 0;
    
    if(scanf("%d", &number) != 1 || number < 0) abort();

    int size = countDigit(number);    
    
    int array[size];

    splitNumberIntoDigits(number, array);

    printArray(array, size);

}