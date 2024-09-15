/*
    In: The file 
    Do: Counts the number of lines in the file
    Out: The number of lines in the file
*/
int countLines(int fd) {
    int rbytes, lines = 1;
    char str[256];
    
    // Read from file
    if((rbytes = read(fd,str,256)) == -1) {
        printf("Error! cant read from the file\n");
        exit(-1);
    }

    // Loop until EOF and whenever you find a '\n' add 1 to lines
    while (rbytes > 0) {
        for (int i = 0; i < rbytes; i++){
                if (str[i] == '\n'){
                lines++;
            }
        }
        if((rbytes = read(fd,str,256)) == -1) {
            printf("Could not read from the file\n");
            exit(-1);
        }
    }
    
    return lines;
}
/*
    In: The file, the input from the user and the line number
    Do: Writes the command to the file
    Out: None
*/
void WriteCommandToFile(int fd, char* input, int line) {
    int wbytes;
    char sLine[256] = "";
    
    // Add the line number to the string
    sprintf(sLine, "%d", line);
    strcat(sLine, ". ");
    strcat(sLine, input);

    // Write to file
    wbytes = write(fd, sLine, strlen(sLine));
    if(wbytes != strlen(sLine)){
        printf("Could not write to file in String Shell\n");
        exit(-1);
    }
}