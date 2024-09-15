#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define BUFF 256

/*
    * In: Sentence, Word, Index
    * Do: Replace in the sentence the current word at Index and place Word in it
*/
int main(int argc, char * argv[]) {

    if(argc != 4){
		printf("incorrect amount of parameters\n");
		exit(-1);
	}

    int i, j = 0, sLen = strlen(argv[2]), index = atoi(argv[3])-1;
    char buff[BUFF];

    // Check if index is out of bounds
    if(index < 0 || index > strlen(argv[1])){
        printf("Index out of bounds\n");
        exit(-1);
    }
    
    // Save to buff the first part of the sentence
    for(i = 0; i < index; i++){
        buff[i] = argv[1][i];
    }

    // Save to buff the new word
    for(i = index; i < index + sLen; i++){
        buff[i] = argv[2][j++];
    }

    // Save to buff the rest of the sentence
    for(i = index + sLen ; i < strlen(argv[1]) ; i++){
        buff[i]= argv[1][i];
    }
    //
    printf("%s\n",buff);

    return 0;
}
