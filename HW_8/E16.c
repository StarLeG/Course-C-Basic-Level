#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    Чаще других
    Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего.
    Гарантируется, что такое число ровно 1.

    Формат входных данных
    10 целых числе через пробел

    Формат результата
    Одно число, которое встречается чаще других.
*/

#define SIZE 10

bool initArray(int *array, const int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1) return true;
        array[i] = n;
    }

    return false;
}

void printArray(const int *array, const int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void bubleSort(int *array, const int size){ 

    for (int i = 0; i < size - 1; i++) {          // Проходы по массиву
        for (int j = 0; j < size - i - 1; j++) {  // Сравнение соседних элементов
            if (array[j] > array[j + 1]) {         // Если текущий элемент больше следующего
                // Меняем элементы местами
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int findMostFrq(const int array[], const int size){
    if(size == 0) return -1;
    int currentNumber = array[0];
    int maxNumber = array[0];
    int currentCount = 1;
    int maxCount = 1;

    for(int i = 1; i < size; i++){
        if(array[i] == currentNumber){
            currentCount++;
        }else{
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxNumber = currentNumber;
            }
            currentNumber = array[i];
            currentCount = 1;
        }
    }
    if (currentCount > maxCount) {
        maxNumber = currentNumber;
    }

    return maxNumber;
}

int main(){
    int array[SIZE] = {0};

    if(initArray(array, SIZE)) abort();

    bubleSort(array, SIZE);

    if(findMostFrq(array, SIZE) == -1) return 0;

    printf("%d", findMostFrq(array, SIZE));

    return 0;
}
