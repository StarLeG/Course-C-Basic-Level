#include <stdio.h>

int main(){
	int a;
	int i = 1;
	
	scanf("%d", &a);
	
	for(; i <= a; i++){
		printf("%d ", i);
		printf("%d ", i * i);
		printf("%d\n", i * i * i);
	}
	
	return 0;
}
