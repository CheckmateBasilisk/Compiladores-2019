#include<stdio.h>
#include<stdlib.h>


//returns a dynamically-allocated, null-temrinated char* read from src until delimiter is met
char *readLine(FILE *src, int DELIMITER){
    int counter =0;
    char *line = NULL;
    char c;
    do{
        c = fgetc(src);
        line = (char *) realloc(line,sizeof(char)*(counter+1));
        line[counter] = c;
        counter++;
    }while(c!=DELIMITER);
    line[counter-1]  = '\0';

    return line;
}
