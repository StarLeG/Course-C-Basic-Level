#include <stdio.h>
#include <stdbool.h>

// Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.

int main(){
    int a;
    bool flag = true;

    scanf("%d", &a);

    while (a != 0){
        int tmp1 = a % 10;
        a /= 10;
        int tmp2 = a % 10;

        if( tmp1 <= tmp2){
            flag = false;
            break;
        }
        a /= 10;
    }
    
    flag ? printf("YES\n") : printf("NO\n");

    return 0;
}