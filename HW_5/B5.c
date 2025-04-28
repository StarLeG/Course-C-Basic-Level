#include <stdlib.h>

// Ввести целое число и найти сумму его цифр. Одно целое число большее или равное нулю.

int main(int argc, char **argv)
{
	int a, sum = 0;
	
	scanf("%d", &a);
	
	if (a < 0) abort();	
	
	
	while( a != 0){
		sum += a % 10;
		a /= 10;
	}
	
	printf("%d\n",sum);
	
	return 0;
}

