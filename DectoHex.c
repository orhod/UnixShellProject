#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 64
/*
    * In: Int
    * Do: Convert and print the recieved number to its binary form
*/
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("incorrect amount of parameters\n");
        exit(-1);
    }
 
    int num = atoi(argv[1]); 
    printf("%X\n", num);
    
    return 0;    
}