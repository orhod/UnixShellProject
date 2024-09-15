#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "Utill.c"

#define BUFF 256
#define ARGS 5

int main(int argc, char * argv[]){

	if(argc != 1){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}
    
	int pid = 0, cFile, supported = 0;
    char buff[BUFF], directory[BUFF] = "./Commands/Math/Math_Commands.txt", *supportedCommands[4]={"Sqrt", "Power", "Solve", "History"};
    
    // Open file to store exectued commands
    if((cFile = open(directory, O_RDWR | O_APPEND, 0777)) == -1){
        printf("File could not be opened or created!\n");
        exit(-1);
    }

    // Count the lines in the file
    int line = countLines(cFile);

    // Loop for the Math Shell
	while(1){ 

        int i = 0;
        char input[BUFF], *arguments[ARGS], *sTemp, sProg[BUFF] = "./";

        // Get input from user
        printf("MathShell>");
        if(fgets(input, BUFF - 1, stdin) == NULL){
            printf("Cannot read user input\n");
            exit(-1);
        }

        // Check if input is empty
        if(strlen(input) == 1){
            continue;
        }

        // Write entered command to the file
        WriteCommandToFile(cFile, input, line);
        line++;

        // Remove trailing newline character (because of fgets)
        input[strcspn(input, "\n")] = '\0';

        // Appends to an arguments array every string from our input (splits by 'space key')
        sTemp = strtok(input, " ");
        while(sTemp != NULL && i < ARGS - 1){
            arguments[i++] = sTemp;
            sTemp = strtok(NULL, " ");  
        }

        // If the command is 'History' we add the parent's name to our sent arguments
        if(strcmp("History", arguments[0]) == 0){
            arguments[i++] = "Math/Math_Commands.txt";
        }
        arguments[i] = NULL;

        // Check if inputed command is supported
        for(i = 0; i < 4; i++){
            if (strcmp(arguments[0], supportedCommands[i]) == 0) {
                supported = 1;
                break;
            }
        }

        // If input equals to "Cls" quit Math shell and return to Standard Shell
        if(strcmp(arguments[0], "Cls") == 0){
            close(cFile);
			exit(1);
		}
        
		// Create a new child process 
        if((pid = fork()) < 0){
            printf("Failure in process creation\n");
            exit(-1);
        }

        // If the process is a child process
		if(pid  == 0){

            // Appends our command string to the string : "./"
            if(supported){
                strcat(sProg, arguments[0]);
                arguments[0] = sProg;

                // Overrides the child process for usable for commands in ./
                execvp(arguments[0], arguments);
            }
			printf("Not Supported\n");
            exit(-1);
		}

		wait(NULL);
	}  

    close(cFile);
    
    return 0;
}