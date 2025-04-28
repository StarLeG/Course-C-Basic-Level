#include <stdio.h>

// Составить функцию, которая определяет наибольший общий делитель двух натуральных и
// привести пример ее использования. int nod(int a, int b)

int nod(int a, int b);

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    if (a <= 0 || a <= 0) return 1;
       
    printf("%d\n", nod(a, b));   

    return 0;
}

int nod(int a, int b){

    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}