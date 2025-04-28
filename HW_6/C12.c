#include <stdio.h>
#include <stdlib.h>

/*
                    Вычислить sin
    Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
    sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...(x в радианах)
    float sinus(float x)

    Формат входных данных
    Одно число от 0 до 90

    Формат результата
    Вещественное число в формате "%.3f"
*/

int power(int n, int p);
double factorial(int n);
float sinus(float x);

int main(){

    float x;
    int result = scanf("%f", &x);
    if(result != 1 || x < 0 || x > 90) abort();

    printf("%.3f\n", sinus(x));

    return 0;
}

int power(int n, int p){
    int pow = n;
    for(int i = 1; i < p; i++){
        pow *= n;
    }
    
    if(p == 0) return 1;

    return pow;
}

double factorial(int n) {

    int fac = 1;

    for(int i = 1; i <= n; i++){
        fac *= i;
    }

    return fac;

}

float sinus(float x){
    // sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...(x в радианах)

    
}