#include <stdio.h>
#include <limits.h>

/*
    Описать функцию вычисления f(x) по формуле:
    f(x)= x*x при -2 ≤ x < 2;
    x*x+4x+5 при x ≥ 2;
    4   при x < -2.
    Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.
*/

int myFoo(int x);

int main(){

    int max = INT_MIN;
    int x;

    scanf("%d", &x);

    while (x != 0)
    {
        int resMyFoo = myFoo(x);

        if(resMyFoo > max){
            max = resMyFoo;
        }

        scanf("%d", &x);
    }
    
    printf("%d\n", max);

    return 0;
}

int myFoo(int x){
    if (x < -2) {
        return 4;
    } else if (x >= 2) {
        return x * x + 4 * x + 5;
    } else { 
        return x * x;
    }
}