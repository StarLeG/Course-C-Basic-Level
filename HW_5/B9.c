#include <stdio.h>
#include <stdbool.h>

//Ввести целое число и определить, верно ли, что все его цифры четные.

int main(){
    int a;
    bool flag = true;

    scanf("%d", &a);

    while (a != 0)
    {
        int tmp = a % 10;
        if(tmp % 2 != 0){
            flag = false;
            break;
        } 
        a /= 10;
    }
    
    flag ? printf("YES\n") : printf("NO\n");
    return 0;
}