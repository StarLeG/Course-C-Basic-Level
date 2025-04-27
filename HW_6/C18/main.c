#include <stdio.h>

// Составить логическую функцию, которая определяет, что текущий символ это цифра.
// Написать программу считающую количество цифр в тексте. int is_digit(char c)

int is_digit(char c);

int main(){
    char ch;
    int cnt = 0;

    do{
        ch = getchar();
        if(is_digit(ch)){
            cnt++;
        }
    }while(ch != '.');

    printf("%d\n", cnt);

    return 0;
}

int is_digit(char c){

    if(c >= 48 && c <= 57) return 1;
    return 0;    
    
}