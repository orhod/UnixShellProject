#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/*
    * In: a, b, c (int)
    * Do: Compute the roots of the quadratic equation ax^2 + bx + c = 0 and print it    
*/
int main(int argc, char * argv[]) {

    if(argc != 4){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}

    int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]);
    float x1, x2;
    float discriminant = ((b * b) - (4 * a * c));
    
    // Check for invalid input
    if (discriminant < 0) {
        printf("No Sol!\n");
        exit(1);
    }

    // Compute the roots
    x1 = (b*(-1) + sqrt(discriminant)) / (2 * a);
    x2 = (b*(-1) - sqrt(discriminant)) / (2 * a);

    // Check if roots are equal
    if(x1 == x2){
        printf("%g\n",x1);
    }
    else{
        printf("%g\n%g\n", x1, x2);
    }

    return 0;
}
