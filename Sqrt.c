#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/*
    * In : Recieve base number (int)
    * Do: Print the root of the number
*/
int main(int argc, char * argv[]) {

    if(argc != 2){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}

    // Returns -1 if our input is negative
    if (atoi(argv[1]) < 0) {
        printf("Math Error!\n");
        exit(-1);
    }

    // Calculates the root of argv[1]
    float num = sqrt(atoi(argv[1]));

    printf("%g\n", num);
    
    return 0;
}