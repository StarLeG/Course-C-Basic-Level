#include <stdio.h>

// Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

int main(){

    int a;

    scanf("%d", &a);
    
    if (a == 0) printf("%d", a);
		else{

			while(a != 0){
				printf("%d", a % 10);
				a /= 10;
			}
		}

    return 0;
}
