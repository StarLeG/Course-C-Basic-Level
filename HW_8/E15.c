#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
                        Положительные и отрицательные
    Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам:
    в одни помещать только положительные, во второй - только отрицательные.
    Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.

    Формат входных данных
    10 целых чисел через пробел.

    Формат результата
    Сперва положительные числа, потом отрицательыне числа, через пробел.
*/

#define SIZE 10

bool initArray(int *array, const int size){
    int n;
    for(int i = 0; i < size; i++){
        if(scanf("%d", &n) != 1 || n < -500 || n > 500) return true;
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

bool  isPositive(const int num){
    return num >= 0 ? true : false;
}

int main(){
    int array[SIZE] = {0};
    int cntPos = -1;
    int cntNeg = -1;

    int arrayPos[SIZE] = {0};
    int arrayNeg[SIZE] = {0};    

    if(initArray(array, SIZE)) abort();

    for(int i = 0; i < SIZE; i++){
        if(array[i] == 0) continue;
        if(isPositive(array[i])){
            arrayPos[++cntPos] = array[i];
        }else{
            arrayNeg[++cntNeg] = array[i];
        }
    }

    if(cntPos == -1 && cntNeg == -1) return 0;

    if(cntPos > 0 && cntNeg > 0){
        cntPos++;
        cntNeg++;
        printArray(arrayPos, cntPos);
        printArray(arrayNeg, cntNeg);
    }

    if(cntPos > 0 && cntNeg == -1){
        cntPos++;
        printArray(arrayPos, cntPos);
    }

    if(cntPos == -1 && cntNeg > 0){
        cntNeg++;
        printArray(arrayNeg, cntNeg);
    }
    return 0;
}