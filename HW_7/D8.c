#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                        От A до B
    Составить рекурсивную функцию, Выведите все числа от A до B включительно,
    в порядке возрастания, если A < B, или в порядке убывания в противном случае.

    Формат входных данных
    Два целых числа через пробел.

    Формат результата
    Последовательность целых чисел.
*/

void numPrint(int A, int B, bool x);

int main(){
    int a, b;
    if(scanf("%d%d", &a, &b) != 2) abort();
    numPrint(a, b, a < b);
    return 0;
}

void numPrint(int A, int B, bool x){
    
    switch ((int)x)
    {
    case 0:
        if(B <= A){
            printf("%d ", A);
            numPrint(--A,B, 0);
        }
        break;
    case 1:
        if(B >= A){
            printf("%d ", A);
            numPrint(++A,B, 1);           
        }
        break;
        
    
    default:
        break;
    }
    

}