#include <stdio.h>

/*
                    Сортировка по взрастанию
    Написать только одну функцию, которая сортирует массив по возрастанию.
    Необходимо реализовать только одну функцию, всю программу составлять не надо.
    Строго согласно прототипу. Имя функции и все аргументы должны быть:
    void sort_array(int size, int a[]).
    Всю программу загружать не надо, только одну эту функцию.
    Можно просто закомментировать текст всей программы, кроме данной функции.

    Формат входных данных
    Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.

    Формат результата
    Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.
*/

void sort_array(int size, int a[]){
     for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

int main(){
    int array[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    int size = sizeof(array) / sizeof(array[0]);

    sort_array(size, array);

    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return 0;
}