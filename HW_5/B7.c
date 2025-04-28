#include <stdio.h>
#include <stdbool.h>

// Ввести целое число и определить, верно ли, что в его записи есть  две одинаковые цифры, НЕ обязательно стоящие рядом.

int main(){
    int a;
    bool flag = false;

    scanf("%d", &a);

    int b;

    while (a != 0)
    {
        int tmp1 = a % 10;
        b = a / 10;       

        while (b != 0)
        {
           int tmp2 = b % 10;
            if (tmp1 == tmp2){
                flag = true;
                break;
            }
           b /= 10;
        }
        
        a /= 10;
        b = a;        
    }
    
    flag ? printf("YES\n") : printf("NO\n");

    return 0;
}