#include <stdio.h>

//Дана последовательность ненулевых целых чисел, в конце последовательности число 0.
// Посчитать количество чисел.

int main(){
    int a;
    int cnt = 0;

    do{
        scanf("%d", &a);
        cnt++;
    }while(a != 0);

    printf("%d\n", cnt - 1);

    return 0;
}