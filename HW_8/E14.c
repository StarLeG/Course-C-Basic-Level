#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
                Более одного раза
    Считать массив из 10 элементов и выделить в другой массив все числа,
    которые встречаются более одного раза.
    В результирующем массиве эти числа не должны повторяться.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    Целые числа через пробел, которые встречаются более одного раза в исходном массиве.
*/

#define SIZE 10

int array2[SIZE];
int cnt = -1;

bool initArray(int *array, int size){
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

void findDuplicates(int arr[], const int size){
     for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {  
            array2[++cnt] = arr[i];
           
            while (i < size && arr[i] == arr[i - 1]) {
                i++;
            }
        }
    }
}

int main(){
    
    int array1[SIZE];  
    
    if(initArray(array1, SIZE)) abort();
    
    bubleSort(array1, SIZE);

    findDuplicates(array1, SIZE);

    if(cnt == -1) return 0;

    printArray(array2, cnt + 1);

    return 0;
}