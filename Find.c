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

    if(argc != 3){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}

    int fd, rbytes = 1, i = 0, j = 0, sLen = strlen(argv[2]);
    char buff[BUFF], strToFind[BUFF];
    
    strcpy(strToFind, argv[2]);

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
        // Check if i is lesser then our string's length and wether j is lesser then rbytes
        while (i < sLen &&  j < rbytes){
            // Check char by char wether the strings are equal if so print 'WIN' (not case sensitive as the example shows)
            if(buff[j] == strToFind[i] || buff[j] == strToFind[i] + 32 || buff[j] == strToFind[i] - 32){
                i++;
                if(i == sLen){
                    printf("WIN\n");
                    exit(1);    
                }
            }
            else{
                i = 0;
            }
            j++;
        }
        // First batch has no string that is equal to the string we look for so we read the next batch from file
        if((rbytes = read(fd, buff, BUFF)) == -1){
            printf("Could not read from file!\n");
            exit(-1);
        }
        j = 0;
    }
    
    printf("Try Again\n");
    close(fd);

    return 0;
}
