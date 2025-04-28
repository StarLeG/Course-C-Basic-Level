#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.

int main(){
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	if (a > b || abs(a) > 100 || abs(b) > 100) abort(); 
	
	for(; a <= b; a++){
		int tmp = pow(a,2);
		printf("%d ",tmp);
	}
	
	printf("\n");
	
	return 0;
}
