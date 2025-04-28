#include <stdio.h>
#include <stdlib.h>

// Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.

int main(){
	int a;	
	
	scanf("%d", &a);
	
	if( a > 100) abort();
	
	for(int i = 1; i <= a; i++){
		printf("%d ", i);
		printf("%d ", i * i);
		printf("%d\n", i * i * i);
	}
	
	return 0;
}
