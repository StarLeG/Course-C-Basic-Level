#include <stdio.h>
#include <stdlib.h>

/*
                            Вычислить cos
    Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)

    cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ... (x в радианах)

    float cosinus(float x)
    Формат входных данных
    Целое число от 0 до 90

    Формат результата
    Вещественное число в формате "%.3f"
*/
float myAbs(float x);
float cosinus(float x);

int main(){

    float degrees;
    scanf("%f", &degrees);
    
    
    if (degrees < 0. || degrees > 90.) {
        printf("0.000\n");
        return 0;
    }
    
    float result = cosinus(degrees);
    printf("%.3f\n", result);
    
    return 0;
}

float myAbs(float x){
    return x < 0 ? x *= -1 : x;
}

float cosinus(float x){
    // cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ... (x в радианах)

    const double PI = 3.14159265358979323846;
    const double EPSILON = 0.001;
    float term = 1.0f;
    int n = 1;  
    
    float res = 1.0f;

    x = x * PI / 180.;

    while (myAbs(term) >= EPSILON)
    {
        term *= (-1) * x * x / ((2 * n - 1) * (2 * n));
        res += term;
        n++;
    }
         
    return res;
}