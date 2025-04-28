#include <stdio.h>
#include <stdbool.h>

// Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».

int main(){
    int a;
    bool flag1 = false;
    bool flag2 = false;

    scanf("%d", &a);

    while (a != 0)
    {
        if(a % 10 == 9) flag1 = true;
        a /= 10;
        if(a % 10 == 9 && flag1) flag2 = true;
        
    }

    if (flag2) flag1 = false;
    
    flag1 ? printf("YES\n") : printf("NO\n");
    return 0;
}