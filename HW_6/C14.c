#include <stdio.h>
#include <stdbool.h>

// Составить функцию логическую функцию, которая определяет, верно ли,
// что сумма его цифр – четное число. Используя эту функцию решить задачу.

bool isEven(int n); 

int main(){
    int n;
    
    scanf("%d", &n);

    isEven(n) ? printf("YES\n") : printf("NO\n");

    return 0;
}

bool isEven(int n){

    int sum = 0;

    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    

    return sum % 2 == 0;

}