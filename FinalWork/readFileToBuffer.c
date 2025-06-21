#include "readFileToBuffer.h"

int readFileToBuffer(char *fileName, char *buffer)
{
    if(fileName == NULL) return -1;

    FILE *input = fopen(fileName, "r");

    if(input == NULL){
        return -2;
    }

    if(fgets(buffer, sizeof(buffer), input) == NULL){                   
          
        return -3;      
    }


    fclose(input);
    return 0;
}
