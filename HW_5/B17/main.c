#include <stdio.h>


// Ввести натурально число и напечатать все числа от 10 до введенного числа - 
// у которых сумма цифр равна произведению цифр

int main(){

    int a;
    
    scanf("%d", &a);

    if(a < 10) return 1; // Если введенное число меньше 10

    for(int i = 10; i <= a; i++){
        int tmp = i;
        int sum = 0;
        int mul = 1;

        while (tmp != 0)
        {
            int digit = tmp %  10;
            sum += digit;
            mul *= digit;
            tmp /= 10;
        }

        if(sum == mul) printf("%d ", i);
        
    }

    printf("\n");

    return 0;
}