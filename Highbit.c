#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    * In: Int
    * Do: Count the amount of bits equal to 1 in our number's binary form
*/
int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("incorrect amount of parameters\n");
        exit(-1);
    }

    int num = atoi(argv[1]), i, bit, counter = 0;

    //  Count the amount of bits equal to 1 in our number's binary form
    for( i = 31; i >= 0; i--) {
        bit = (num >> i) & 1;
        if (bit == 1) {
            counter++;
        }
    }
    
    printf("%d\n", counter);

    return 0;
}
