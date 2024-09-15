#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF 256

int main(int argc, char * argv[]){
    
	if(argc != 1){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}
    
	int pid = 0 , cFile, wbytes, supported = 0;
    char buff[BUFF], directory[BUFF] = "./Commands/Logic";
    struct stat st = {0};
    
    // Create a 'Logic' folder if it doesn't exist
    if (stat(directory, &st) == -1) {
        mkdir(directory, 0700);
    }
    strcat(directory, "/Logic_Commands.txt");
    
    // Create a txt file to store all executed commands
    if((cFile = open(directory, O_WRONLY | O_CREAT , 0777)) == -1){
        printf("File could not be opened or created!\n");
        exit(-1);
    }
    close(cFile);

    // Create a new child process 
    if((pid = fork()) < 0){
        printf("Failure in process creation\n");
        exit(-1);
    }

	if(pid == 0){
        execlp("./Logic_shell", "Logic_shell", NULL);
        printf("Error in logic_shell\n");
        exit(-1);
    }
    
	wait(NULL);

    return 0; 
}