#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    * In: Recieve a base number and an exponent (int)
    * Do: Print base^exp
*/
float main(int argc, char * argv[]) {
     if(argc != 3){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}
    
    int base = atoi(argv[1]), exp = atoi(argv[2]);
    float result = 1;

    // Check if undefined mathematically
    if(base == 0 && exp <= 0) {
        printf("Cant divide by 0\n");
        exit(-1);
    }
    // Check if the exp is negetive
    else if(exp < 0){
        exp = -1 * exp;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        result = 1/result;
    	printf("%g\n", result);
    }

    // Check if base = 0
    else if (base == 0){
        printf("%d\n", 0);
        return 0;
    }

    // Compute base^exp
    else{
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        printf("%g\n", result);
    }
    
    return 0;
}
