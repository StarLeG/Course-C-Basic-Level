#include <stdio.h>
#include <stdbool.h>

// Проверить число на простоту.

int main(){

    int n;

    scanf("%d", &n);

    if(n <= 1){
        printf("NO\n");
        return 0;
    }

    if(n <= 3){
        printf("YES\n");
        return 0;
    } 
    
    if (n % 2 == 0 || n % 3 == 0) {
        printf("NO\n");
        return 0;
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}