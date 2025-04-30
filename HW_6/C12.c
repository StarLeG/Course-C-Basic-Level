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
float myAbc(float x);
float sinus(float x);

int main(){

    float x;
    int result = scanf("%f", &x);
    if(result != 1 || x < 0 || x > 90) abort();

    printf("%.3f\n", sinus(x));

    return 0;
}

float myAbc(float x){
    return x < 0 ? x *= -1 : x;
}

float sinus(float x){
    // sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...(x в радианах)
    const double PI = 3.14159265358979323846;

    float rad = x * PI / 180;
    float res = 0.0f;
    float term = rad;
    int n = 1;

    while (myAbc(term) >= 0.001) {
        res += term;
        term *= -rad * rad / ((2 * n) * (2 * n + 1));
        n++;
    }

    return res;
}