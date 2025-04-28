#include <stdio.h>


// Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.

int main(){
	
	int a, cnt = 0; 
	
	scanf("%d", &a);
	
	while(a != 0){
		a /= 10;
		cnt++;
	}
	
	cnt == 3 ? printf("YES\n") : printf("NO\n");	
	
	return 0;
}
