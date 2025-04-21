#include <stdio.h>

int main(){
	int a;	
	
	scanf("%d", &a);
	
	for(int i = 1; i <= a; i++){
		printf("%d ", i);
		printf("%d ", i * i);
		printf("%d\n", i * i * i);
	}
	
	return 0;
}
