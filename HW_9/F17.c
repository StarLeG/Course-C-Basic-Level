/*
                        След матрицы
    Составить функцию которая находит след матрицы в двумерном массиве.
    Показать пример ее работы на матрице из 5 на 5 элементов.
    След матрицы - это сумма элементов на главной диагонали.

    Формат входных данных
    25 целых чисел через пробел.

    Формат результата
    Одно целое число.
*/

#include <stdio.h>

#define SIZE 5

int matrix_trace(int mat[SIZE][SIZE]) {
    int trace = 0;
    for (int i = 0; i < SIZE; i++) {
        trace += mat[i][i]; 
    }
    return trace;
}

int main() {
    int matrix[SIZE][SIZE];
        
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
        
    printf("%d\n", matrix_trace(matrix));
    
    return 0;
}