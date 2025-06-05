#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
                                Пропущенное число
    В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке,
    но одно из чисел пропущено (остальные встречаются ровно по одному разу).
    N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.

    Формат входных данных
    Последовательность целых чисел от M до N. M, N не превосходит 1000.

    Формат результата
    Одно целое число
*/

int main(){
    int num;
    int min = INT_MAX;  
    int max = INT_MIN;  
    int present[1001] = {0}; 

    
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        
        if (num < min) min = num;
        if (num > max) max = num;
        
        present[num] = 1;
    }
   
    for (int i = min; i <= max; i++) {
        if (!present[i]) {
            printf("%d\n", i);
            break;
        }
    } 
    
    system("pause");

    return 0;
}