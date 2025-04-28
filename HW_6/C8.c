#include <stdio.h>

// Составить функцию, которая переводит латинскую строчную букву в заглавную.
// И показать пример ее использования.

char toUpper(char ch);

int main(){
    char c;

    c = getchar();

    while (c != '.')
    {        
        putchar(toUpper(c));
        c = getchar();
    }
   
    return 0;
}

char toUpper(char ch){
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    return ch;
}