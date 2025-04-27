#include <stdio.h>
#include <stdlib.h>

// Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.
// Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9

int myConverFoo(int n, int p);

int main(){
    int N, P;

    scanf("%d %d", &N, &P);

    if(N < 0 || P > 9) abort();

    printf("%d\n", myConverFoo(N, P));

    return 0;
}

int myConverFoo(int n, int p){
    
    if(n == 0) return 0;

    int result = 0;
    int position = 1;

    while (n > 0)
    {
        int digit = n % p;
        result += digit * position;
        n /= p;
        position *= 10;        
    }
    
    return result;
}