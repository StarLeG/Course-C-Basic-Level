/*
                            Массив максимумов
    Дана целочисленная квадратная матрица 10 х 10.
    реализовать алгоритм вычисления суммы максимальных элементов из каждой строки.
    Напечатать значение этой суммы. Предполагается, что в каждой строке такой элемент единственный.
    Реализовать функцию поиска максимума в строке из 10 элементов

    Формат входных данных
    10 строк состоящих из 10 целых чисел через пробел.

    Формат результата
    Одно целое число

*/

#include <stdio.h>

#define SIZE 10

int findMaxInRow(int row[SIZE]) {
    int max = row[0];
    for (int i = 1; i < SIZE; i++) {
        if (row[i] > max) {
            max = row[i];
        }
    }
    return max;
}

int main() {
    int matrix[SIZE][SIZE];
    int sum = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        sum += findMaxInRow(matrix[i]);
    }
   
    printf("%d\n", sum);

    return 0;
}
