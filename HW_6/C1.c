#include <stdio.h>

//  Составить функцию, модуль числа и привести пример ее использования.

int myAbs(int num);

int main(){
    int n;

    scanf ("%d", &n);

    printf("%d\n",myAbs(n));

    return 0;
}

int myAbs(int num){
    return (num < 0) ? -num : num;
}