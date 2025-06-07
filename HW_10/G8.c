/*
                                Числа в массив
    В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
    Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
    Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
    Вывести массив по возрастанию в файл output.txt.

    Формат входных данных
    Строка из английских букв, цифр и знаков препинания

    Формат результата
    Последовательность целых чисел отсортированная по возрастанию
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 1000

int extractNumbers(const char *str, int *numbers, int max_numbers) {
    if (!str || !numbers || max_numbers <= 0) return -1;

    int count = 0;
    int num = 0;
    bool in_number = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0'); 
            in_number = true;
        } else {
            if (in_number) {
                if (count < max_numbers) {
                    numbers[count++] = num;
                }
                num = 0;
                in_number = false;
            }
        }
    }
    
    if (in_number && count < max_numbers) {
        numbers[count++] = num;
    }

    return count;
}

void bubleSort(int *array, const int size){ 

    for (int i = 0; i < size - 1; i++) {          
        for (int j = 0; j < size - i - 1; j++) {  
            if (array[j] > array[j + 1]) {     
                
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input == NULL || output == NULL){        
        fputs("Error opening file.\n", stderr);
        return -1;
    }

    char buffer[SIZE] = {'\0'};

    if(fgets(buffer, sizeof(buffer), input) == NULL){
       fputs("The file is empty or reading error.\n", stderr);
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    int lenght = strlen(buffer);

    int digits_array[lenght];
    
    for(int i = 0; i < lenght; i++){
        digits_array[i] = 0;
    }

    int size = extractNumbers(buffer, digits_array, lenght);

    
    
    if(size < -1){
        return -1;
    }else{
        bubleSort(digits_array, size);
        for(int i = 0; i < size; i++){
           fprintf(output,"%d ", digits_array[i]); 
       }
    }

    fclose(input);
    fclose(output); 

    return 0;
}