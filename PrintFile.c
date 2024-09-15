#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define BUFF 256

/*
    * In: String
    * Do: Print the content of the file we got the name of
*/
int main(int argc, char * argv[]) {
    if(argc != 2){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}

    int fd, rbytes = 1;
    char buff[BUFF];

    // Open a file with the name give by the user
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        printf("Failure in opening the file\n");
        exit(-1);
    }

    // Read from opened file to buff array
    if((rbytes = read(fd, buff, BUFF)) == -1){
        printf("Could not read from file!\n");
        exit(-1);
    }

    // Print buff and keep reading from file into buff untill file is empty
    while(rbytes > 0){
        printf("%s\n", buff);   
        if((rbytes = read(fd, buff, BUFF)) == -1){
            printf("Could not read from file!\n");
            exit(-1);
        }
    }
    
    close(fd);
    
    return 0;
}
