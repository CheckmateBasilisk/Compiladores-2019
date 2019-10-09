#include<stdio.h>
#include<stdlib.h>

//returns a dynamically allocated, null-terminated string read from stream until delimiter is met
char *readLine(FILE *stream, int delimiter){
    char *line = NULL;
    char c;
    int counter = 0;

    do{
        c = fgetc(stream);
        line = (char *) realloc(line, (counter+1) * sizeof(char));
        line[counter] = c;
        counter++;
    }while(c != delimiter);
    line[counter-1]  = '\0';

    return line;
}
