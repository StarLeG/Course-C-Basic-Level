/*                      Больше среднего
    Определить количество положительных элементов квадратной матрицы,
    превышающих по величине среднее арифметическое всех элементов главной диагонали.
    Реализовать функцию среднее арифметическое главной диагонали.

    Формат входных данных
    5 строк по 5 целых чисел через пробел

    Формат результата
    Одно целое число 
*/

#include <stdio.h>

#define SIZE 5

double averageMainDiagonal(int matrix[SIZE][SIZE]) {
    double sum = 0.0;
    for (int i = 0; i < SIZE; i++) {
        sum += matrix[i][i];
    }
    return sum / SIZE;
}

int main() {
    int matrix[SIZE][SIZE];
    int count = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }    
    
    double avg = averageMainDiagonal(matrix);    
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] > 0 && matrix[i][j] > avg) {
                count++;
            }
        }
    }    

    printf("%d\n", count);
    
    return 0;
}