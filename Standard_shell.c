#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF 256
#define ARGS 5

int main(int argc, char * argv[]){
    
	if(argc != 1){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}
    
	int pid = 0, exitFlag = 1;

    // Create a Commands folder
	mkdir("Commands",0777);
	
	while(exitFlag){
        
        int i = 0, supported = 0;
        char input[BUFF], *arguments[ARGS], *sTemp, sProg[BUFF] = "./", *supportedCommands[4]={"exit","Math","Logic","String"};

        // Get input from user
        printf("StandShell>");
        if(fgets(input,BUFF - 1, stdin) == NULL){
            printf("Cannot read user input\n");
            exit(-1);
        }
        
        // Check if input is empty
        if(strlen(input) == 1){
            continue;
        }

        // Remove trailing newline character (because of fgets)
        input[strcspn(input, "\n")] = '\0';

        // Appends to an arguments array every string from our input (splits by 'space key')
        sTemp = strtok(input, " ");
        while(sTemp != NULL && i < ARGS - 1){
            arguments[i++] = sTemp;
            sTemp = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        // Check if inputed command is supported
        for(i = 0; i < 4; i++){
            if (strcmp(arguments[0], supportedCommands[i]) == 0) {
                supported = 1;
                break;
            }
        }
        
        // If the command is 'exit' we exit the program
        if(strcmp(arguments[0],"exit") == 0 ){  
            exitFlag = 0;
        }

		// Create a new child process 
        if((pid = fork()) < 0){
            printf("Failure in process creation\n");
            exit(-1);
        }
		if(pid  == 0){
            
            // Overrides the child process for usable for commands in /bin
			execvp(arguments[0], arguments);

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
    
	return 0;
}