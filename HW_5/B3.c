#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
// Два целых числа по модулю не больше 100

int main(){
	
	int a, b, sum = 0;
	
	scanf("%d %d", &a, &b);
	
	if(abs(a) > 100 || abs(b) > 100) abort();
	
	for(; a <= b; a++){
		sum += pow(a, 2);
				
	}
	
	printf("%d\n", sum);	
	
	return 0;
}
