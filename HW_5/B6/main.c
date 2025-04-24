#include <stdio.h>
#include <stdbool.h>

// Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.

int main(int argc, char **argv)
{
	int a;
	bool flag = false;
	scanf("%d", &a);

	while(a != 0){
		int tmp1 =  a % 10;
		a /= 10;
		int tmp2 =  a % 10;
		if (tmp1 == tmp2){
			flag = true;
			break;
		}
	}

	flag ? printf("YES\n") : printf("NO\n");
		
		
	return 0;
}

