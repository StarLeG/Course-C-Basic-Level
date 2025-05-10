#include <stdio.h>
#include <stdlib.h>

/*
                             Количество 1
    Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.

    Формат входных данных
    Натуральное число

    Формат результата
    Целое число - количество единиц в двоичной записи числа.
*/

int unitsCounter(int number);
 
int main(){
    int n;
    if(scanf("%d", &n) != 1) abort();

    printf("%d\n", unitsCounter(n));

    return 0;
}

int unitsCounter(int number){
   
    #if 0
        int cnt = 0;
    
        while (number != 0)
        {
            cnt += number & 1;
            number >>= 1;
        }  

        return cnt;
    #endif

    #if 1
        if (number == 0) return 0;
        return (number & 1) + unitsCounter(number >> 1);
    #endif

}