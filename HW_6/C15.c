#include <stdio.h>



// Составить функцию логическую функцию, которая определяет, верно ли,
// что в заданном числе все цифры стоят по возрастанию.
// Используя данную функцию решить задачу. int grow_up(int n)

int grow_up(int n);

int main(){

    int n;

    scanf("%d", &n);

    grow_up(n) ? printf("YES\n") : printf("NO\n");

    return 0;
}

int grow_up(int n){
  
    int a = n % 10;
    n /= 10;

    while (n != 0)    
    {
        int b = n % 10;               
        
        if (b >= a){
            
            return 0;
        }

        a = b;

        n /= 10;
    }
    
    return 1;
}