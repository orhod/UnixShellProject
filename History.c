#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF 256
/*
    * In: String (shell name)
    * Do: Prints the history of the shell commands
*/ 
int main (int argc, char * argv[]){
    if (argc != 2){ 
        printf("incorrect amount of parameters\n");
		exit(-1);
    }

    // Create prompt for our path to our history file
    char directory[BUFF] = "./Commands/", buff[BUFF], *print;
    int fd_from, rbytes = 1;
    // Creates the path: ./Commands/Math/Math_Commands.txt
    strcat(directory, argv[1]);

    if((fd_from = open(directory, O_RDONLY,0)) == -1){
        printf("Failure in opening the file\n");
        exit(-1);
    }
    
    // Read from file and prints it to the terminal
    while(rbytes > 0){
        if(rbytes = read(fd_from, buff, BUFF) == -1){
            printf("Could not read from file\n");
            exit(-1);
        }
        printf("%s", buff);
    }
    
    close(fd_from);
    
    return 0;
}
