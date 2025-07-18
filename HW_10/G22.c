/*
    Soundex
    Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет,
    похожи ли два английских слова по звучанию. На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
    Если коды двух слов совпадают, то слова, как правило, звучат похоже.

    Вам требуется реализовать этот алгоритм. Он работает так:

    Первая буква слова сохраняется.
    В остальной части слова:
    буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; оставшиеся буквы (согласные)
    заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
    1: b, f, p, v
    2: c, g, j, k, q, s, x, z
    3: d, t
    4: l
    5: m, n
    6: r
    Любая последовательность одинаковых цифр сокращается до одной такой цифры.
    Итоговая строка обрезается до первых четырёх символов. Если длина строки меньше требуемой,
    недостающие символы заменяются знаком 0.

    Примеры:
    аmmonium → ammnm → a5555 → a5 → a500
    implementation → implmnttn → i51455335 → i514535 → i514

    Формат входных данных
    Во входном файле input.txt находится одно непустое слово, записанное строчными латинскими буквами.
    Длина слова не превосходит 20 символов.

    Формат результата
    Напечатайте четырёхбуквенный код, соответствующий слову в файл output.txt.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 21

int getSoundexDigit(char c) {
    switch(tolower(c)) {
        case 'b': case 'f': case 'p': case 'v': 
            return 1;
        case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
            return 2;
        case 'd': case 't':
            return 3;
        case 'l':
            return 4;
        case 'm': case 'n':
            return 5;
        case 'r':
            return 6;
        default:
            return 0; 
    }
}

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL)
    {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        return -1;
    }

    char buffer[LEN] = {'\0'};

    if (fgets(buffer, sizeof(buffer), input) == NULL)
    {
        fputs("The file is empty or reading error.\n", stderr);
        return -1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    fclose(input);

    char soundex[5] = "0000";
    int soundexPos = 0;

     if (buffer[0] != '\0') {
       
        soundex[soundexPos++] = buffer[0];
        
        int previous_digit = 0;
        for (int i = 1; buffer[i] != '\0' && soundexPos < 4; i++) {
            int current_digit = getSoundexDigit(buffer[i]);            
            
            if (current_digit == 0) continue;            
            
            if (current_digit == previous_digit) continue;            
            
            soundex[soundexPos++] = '0' + current_digit;
            previous_digit = current_digit;
        }
    }

    fprintf(output, "%s", soundex);

    fclose(output);

    return 0;
}