#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    * Do: Exit the shell program and delete all files and directories
*/

int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("incorrect amount of parameters\n");
        exit(-1);
    }
    // print an exit msg
    printf("Goodbye...\n");
    
    // Delete all files and directories
    execlp("rm", "rm", "-fr", "Commands", NULL);
    
    return 0;
}