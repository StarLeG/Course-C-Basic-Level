#include <stdio.h>

/*
    Максимум в массиве
    Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
    Прототип функции: int find_max_array(int size, int a[])

    Формат входных данных
    Массив состоящий из целых чисел.
    Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.

    Формат результата
    Одно целое число
*/

int find_max_array(int size, int a[]){

    /* int max = a[0];
    
    for(int i = 1; i < size; i++){
        if(max < a[i]) max = a[i];
    } */

    int max = *a; 
    
    for (int *p = a + 1; p < a + size; p++) {
        if (max < *p) {
            max = *p;
        }
    }

    return max;

}

int main(){

    int array[] = {773, 307, 371, 548, 531, 765, 402, 27, 573, 591, 217,
                     859, 662, 493, 173, 174, 125, 591, 324, 231, 130, 394,
                     573, 65, 570, 258, 343, 3, 586, 14, 785, 296, 140, 726,
                     598, 262, 807, 794, 510, 465, 66, 895, 182, 218, 302, 34,
                     205, 252, 687, 660, 952, 737, 2, 32, 310, 680, 36, 139, 346,
                     139, 489, 217, 767, 544, 158, 774, 883, 154, 802, 136, 569, 377,
                     867, 423, 224, 176, 118, 660, 513, 734, 45, 978, 983, 749, 909, 601,
                     270, 147, 433, 737, 789, 304, 842, 769, 815, 503, 190, 399, 3};

    int size = sizeof(array) / sizeof(array[0]);     
    
    printf("%d\n", find_max_array(size, array));

    return 0;
}