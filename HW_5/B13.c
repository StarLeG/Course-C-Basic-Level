#include <stdio.h>

//Посчитать количество четных и нечетных цифр числа.

int main(){

    int a;
    int cntPos = 0;
    int cntNeg = 0;

    scanf("%d", &a);

    while (a != 0)
    {
        int tmp = a % 10;
        if(tmp % 2 == 0 ){
            cntPos++;
        }else{
            cntNeg++; 
        }

        a /= 10;
    }

    printf("%d %d\n", cntPos, cntNeg);
    
    return 0;
}