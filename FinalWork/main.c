#include <stdio.h>
#include "temp_api.h"

int main(){

    addRecord(2023, 1, 15, 12, 30, -5);
    addRecord(2023, 1, 15, 18, 45, -7);
    addRecord(2023, 2, 20, 10, 15, 10);
    addRecord(2023, 2, 21, 9, 0, 8);
    addRecord(2023, 12, 31, 23, 59, -15);

    printf("Monthly Statistics for 2023:\n");
    printMonthlyStats(2023);

    printf("\nYearly Statistics for 2023:\n");
    printYearlyStats(2023);

    return 0;
}