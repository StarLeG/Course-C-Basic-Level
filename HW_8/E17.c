#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                    Только один раз
    Дан массив из 10 элементов. В массиве найти элементы,
    которые в нем встречаются только один раз, и вывести их на экран.

    Формат входных данных
    10 целых чисел через пробел

    Формат результата
    Элементы которые встречаются только один раз через пробел
*/

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

bool isUniqueNumb(const int array[], const int size, const int target){
     int cnt = 0;
    for(int i = 0; i < size; i++){      
        if(array[i] == target){
            cnt++;
            if(cnt > 1) return false;
        }
        // else if(array[i] > target) break; // для упорядоченного массива
    }

    return (cnt == 1) ? true : false;
}

int main(){
    #define SIZE 10
    int array[SIZE] = {0};
    int arrayFind[SIZE] = {0};
    int idx = -1;

    if(initArray(array, SIZE)) abort();

    //bubleSort(array, SIZE); // для упорядовачивания массива

    for(int i = 0; i < SIZE; i++){
        if(isUniqueNumb(array, SIZE, array[i])){
            arrayFind[++idx] = array[i];
        }
    }

    (idx != -1) ? printArray(arrayFind, ++idx) : exit(0);

    return 0;
}