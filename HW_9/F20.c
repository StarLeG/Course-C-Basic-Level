/*
                Четные и нечетные
    Дан целочисленный массив из 10 элементов.
    Необходимо определить количество четных и нечетных чисел.
    Если количество чётных чисел больше, чем количество нечётных,
    заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи.
    Если количество нечётных чисел больше или равно количеству чётных,
    заменить каждое чётное число на произведение чётных цифр в его десятичной записи.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    10 целых чисел через пробел
*/

#include <stdio.h>

#define SIZE 10


int productOfOddDigits(int num) {
    num = num < 0 ? -num : num; 
    int product = 1;
    int has_odd = 0;
    
    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 != 0) {
            product *= digit;
            has_odd = 1;
        }
        num /= 10;
    }
    
    return has_odd ? product : 0;
}


int productOfEvenDigits(int num) {
    num = num < 0 ? -num : num; 
    int product = 1;
    int hasEven = 0;
    
    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0 && digit != 0) {
            product *= digit;
            hasEven = 1;
        }
        num /= 10;
    }
    
    return hasEven ? product : 0;
}

int main() {
    int arr[SIZE];
    int evenCount = 0, oddCount = 0;
    
    // Чтение массива и подсчет четных/нечетных
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }    
  
    if (evenCount > oddCount) {        
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] % 2 != 0) {
                arr[i] = productOfOddDigits(arr[i]);
            }
        }
    } else {        
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] % 2 == 0) {
                arr[i] = productOfEvenDigits(arr[i]);
            }
        }
    }
    
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    getchar();
    
    return 0;
}