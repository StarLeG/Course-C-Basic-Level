#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
            Переставить цифры
    Переставить цифры в числе так, что бы получилось максимальное число.

    Формат входных данных
    Одно целое не отрицательное число

    Формат результата
    Целое не отрицательное число
*/

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

void bubleSort(int *array, const int size){ 

    for (int i = 0; i < size - 1; i++) {          // Проходы по массиву
        for (int j = 0; j < size - i - 1; j++) {  // Сравнение соседних элементов
            if (array[j] < array[j + 1]) {         // Если текущий элемент больше следующего
                // Меняем элементы местами
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int splitDigitsInToNumber(const int* array, const int size){
    int number = 0;

    for (int i = 0; i < size; i++) {
        number = number * 10 + array[i]; 
    }

    return number;
}

int main(){
    int number = 0;
    if(scanf("%d", &number) != 1 || number < 0) abort();

    int size = countDigit(number);
    int array[size];

    splitNumberIntoDigits(number, array);

    bubleSort(array, size);

    printf("%d\n", splitDigitsInToNumber(array, size));

    return 0;
}