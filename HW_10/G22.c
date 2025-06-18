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

#define LEN 1001

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
    fclose(output);

    return 0;
}