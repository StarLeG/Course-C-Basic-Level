#include <stdio.h>
#include <stdbool.h>

/*
                        Скобки
    Проверить строку состоящую из скобок "(" и ")" на корректность.

    Формат входных данных
    На вход подается строка состоящая из символов '(', ')' и заканчивающаяся символом '.'. Размер строки не более 1000 символов.

    Формат результата
    Необходимо напечатать слово YES если скобки расставлены верно и NO в противном случае.
*/

bool isStrGood();

int main(){
    
    isStrGood() ? printf("YES\n") : printf("NO\n");

    return 0;
}

bool isStrGood(){

    const int MAX_LENGTH = 1000;
    char ch;
    int balance = 0;
    int charCnt = 0;

    
    while ((ch = getchar()) != '.' && charCnt <= MAX_LENGTH) {
        charCnt++;
        if (ch == '(') {
            balance++;
        } else if (ch == ')') {
            balance--;
            if (balance < 0) {  
                return false;
            }
        }

        if (ch != '.' && charCnt > MAX_LENGTH) {
            return false;
        }
        
    }
    
    return balance == 0; 

}