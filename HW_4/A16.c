#include <stdio.h>
#include <stdlib.h>

/*
                        В порядке возрастания
    Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.

    Формат входных данных
    Три целых числа

    Формат результата
    Одно слово YES или NO
*/

int main()
{
    int a, b, c;


    int result = scanf("%d %d %d", &a, &b, &c);
    if(result != 3) abort();

    if (a < b && b < c){
        printf("YES\n");
    }else{
        printf("NO\n");
    }


    return 0;
}
