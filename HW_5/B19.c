#include <stdio.h>

// Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

int main(){
    int n;
    int sum = 0;

    scanf("%d", &n);

    while(n != 0){
        sum += n % 10;
        n /= 10;        
    }

    sum == 10 ? printf("YES\n") : printf("NO\n");

    return 0;
}