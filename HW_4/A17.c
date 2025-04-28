#include <stdio.h>
#include <stdlib.h>

/*
                    Какое время года
    Ввести номер месяца и вывести название времени года.

    Формат входных данных
    Целое число от 1 до 12 - номер месяца.
    Формат результата
    Время года на английском: winter, spring, summer, autumn
*/

int main()
{
    int numbMonth;

    int result = scanf("%d", &numbMonth);
    if(result != 1) abort();

    if(numbMonth < 1 || numbMonth > 12) abort();

    switch (numbMonth) {
    case 1:        
    case 2:       
    case 12:
        printf("winter\n");
        break;
    case 3:        
    case 4:       
    case 5:
        printf("spring\n");
        break;
    case 6:        
    case 7:        
    case 8:
        printf("summer\n");
        break;
    case 9:        
    case 10:        
    case 11:
        printf("autumn\n");
        break;
    default:
        break;
    }

    return 0;
}
