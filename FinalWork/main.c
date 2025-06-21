#include <stdio.h>
#include "temp_api.h"
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "readFileToBuffer.h"


#define SIZE 1000000

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    addRecord(2023, 1, 15, 12, 30, -5);
    addRecord(2023, 1, 15, 18, 45, -7);
    addRecord(2023, 2, 20, 10, 15, 10);
    addRecord(2023, 2, 21, 9, 0, 8);
    addRecord(2024, 2, 21, 9, 0, 8);
    addRecord(2017, 2, 21, 9, 0, 8);
    addRecord(2018, 2, 12, 9, 0, 8);
    addRecord(2022, 12, 31, 23, 59, -15);

    int result = 0;
    // opterr = 0;
    char fileName[255] = {'\0'};

    while ((result = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (result)
        {
        case 'h':
            FILE *file = fopen("help.txt", "r");
            if (file == NULL)
            {
                return 1;
            }

            char buff[1024];

            while (fgets(buff, sizeof(buff), file))
            {
                fputs(buff, stdout);
            }

            fclose(file);
            return 0;

        case 'f':
            strcpy(fileName, optarg);
            break;
        case 'm':
            int month = atoi(optarg);
            if (month < 1 || month > 12)
            {
                printf("Invalid month! Month should be between 1 and 12.\n");
                return 1;
            }
            printStatsForMonthAllYears(month);
            return 0;
        case '?':
            printf("Error found !\n");
            break;
        }
    }

    char buffer[SIZE] = {'\0'};

    result = readFileToBuffer(fileName, buffer);

    //printf("%d\n", result);

    printf("Monthly Statistics for 2023:\n");
    printMonthlyStats(2023);

    printf("\nYearly Statistics for 2023:\n");
    printYearlyStats(2023);

    return 0;
}