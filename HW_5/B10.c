#include <stdio.h>
#include <stdbool.h>

// Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.

int main(){
    int a;
    bool flag = true;

    scanf("%d", &a);

    int prevDigit = a % 10;
    a /= 10;

    while (a != 0){
        int currentDigit = a % 10;

        if( currentDigit >= prevDigit){
            flag = false;
            break;
        }

        prevDigit = currentDigit;
        a /= 10;
    }
    
    flag ? printf("YES\n") : printf("NO\n");

    return 0;
}