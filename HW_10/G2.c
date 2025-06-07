/*
    Строка и цифры
    Считать число N из файла input.txt. Сформировать строку из N символов.
    N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания,
    кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt

    Формат входных данных
    Четное N ≤ 26

    Формат результата
    Строка из английских букв и цифр
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *input; 
    FILE *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if(input == NULL || output == NULL ) {
        printf("Error opening files\n");
        return 1;
    }

    int N;
    if(fscanf(input, "%d", &N) != 1 || N > 26 || N < 1) return 1;

    char buffer[27] = {'\0'};
    

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {           
            buffer[i] = 'A' + (i / 2);
        } else {            
            int num_pos = (i / 2) % 4;  
            buffer[i] = '2' + num_pos * 2;
        }
    }

    fprintf(output, "%s", buffer);

    fclose(input);
    fclose(output);
  

    return 0;
}