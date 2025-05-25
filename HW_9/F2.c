#include <stdio.h>
#include <stdint.h>

/*
                            Четные в начало
    Написать только одну функцию, которая ставит в начало массива все четные элементы,
    а в конец – все нечетные. Не нарушайте порядок следования чисел между собой.
    Строго согласно прототипу:.
    void sort_even_odd(int n, int a[])

    Формат входных данных
    Функцийя принмате на вход целые числа

    Формат результата
    Отсортированный исходный массив
*/

/* void sort_array(int size, int a[]){
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
} */

void sort_even_odd(int n, int a[]){
    if(n == 0) return;
    int evenNumb[n];
    int oddNumb[n];
    int idxEven = -1;
    int idxOdd = -1;
    
    
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            evenNumb[++idxEven] = a[i];            
        }else{
            oddNumb[++idxOdd] = a[i];
        } 
    }
    
   /*  for(int i = 0; i < idxEven + 1; i++){
        printf("%d ", evenNumb[i]);
    }

    for(int i = 0; i < idxOdd + 1; i++){
        printf("%d ", oddNumb[i]);
    }  
    
    printf("\n"); */

    for(int i = 0; i < idxEven + 1; i++){
        a[i] = evenNumb[i];
    }

    int idx = 0;

    for(int i = idxEven + 1; i < n; i++){
        a[i] = oddNumb[idx++];
    }

}

int main(){
    int array[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    //sort_array(size, array);
    sort_even_odd(size, array); 
    
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}