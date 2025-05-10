#include <stdio.h>
#include <stdlib.h>

/*
    Монотонная последовательность
    Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
    Выведите первые n членов этой последовательности.

    Формат входных данных
    Натуральное число.

    Формат результата
    Последовательность целых чисел.
*/

void monotonicSequence(int n);

int main(){
    int n;
    if(scanf("%d", &n) != 1 || n < 1) abort();

    monotonicSequence(n);

    return 0;
}

void monotonicSequence(int n){

    #if 1
        int i = 1;
        int j = 0;
        int cnt = 0;

        if(n == 1){
            printf("%d ", 1);
            return;
        } 

        if(n == 2){
            printf("%d %d", 1, 2);
            return;
        }

        while (i < n)
        {
        
            j = 0;

            while (j < i)
            {            
                printf("%d ", i);            
                j++;
                cnt++;
                if(cnt >= n) goto FINISH;
            }

            i++;                
        
        }   

        FINISH:
            return;

    #endif       
    
}