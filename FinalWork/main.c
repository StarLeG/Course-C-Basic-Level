#include <stdio.h>
#include "temp_api.h"
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "readFileToBuffer.h"

#define SIZE 1000000



int main(int argc, char *argv[]){
    SetConsoleOutputCP(CP_UTF8); 
    
    addRecord(2023, 1, 15, 12, 30, -5);
    addRecord(2023, 1, 15, 18, 45, -7);
    addRecord(2023, 2, 20, 10, 15, 10);
    addRecord(2023, 2, 21, 9, 0, 8);
    addRecord(2023, 12, 31, 23, 59, -15);

    int result = 0;
    char fileName[255] = {'\0'};

    while ( (result = getopt(argc,argv,"hf:m:")) != -1){
        switch (result)
        {
        case 'h':
            /* code */
            break;
        case 'f':            
            strcpy(fileName, optarg);  
            break;
        case 'm':        
            /* code */
            break;
        case '?':
            printf("Error found !\n");
            break;
        }
    }

    char buffer[SIZE] = {'\0'};

    result = readFileToBuffer(fileName, buffer);

    printf("%d\n", result);

   
    

    /* printf("Monthly Statistics for 2023:\n");
    printMonthlyStats(2023);

    printf("\nYearly Statistics for 2023:\n");
    printYearlyStats(2023); */

    
   

    return 0;
}