#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
    * In: Int
    * Do: Convert and print the recieved number to its binary form
*/
int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("incorrect amount of parameters\n");
        exit(-1);
    }

    int num = atoi(argv[1]), i, bit, nonZeroFound = 0;
    if(num == 0){
        for( i = 31; i >= 0; i--) {
            printf("0");
        }
        printf("\n");
        return 0;
    }
    // Convert a decimal integer to a binary array
    for( i = 31; i >= 0; i--) {
        bit = (num >> i) & 1;
        if (bit || nonZeroFound || i == 0) {
            printf("%d", bit);
            nonZeroFound = 1;
        }
    }
    printf("\n");

    return 0;
}