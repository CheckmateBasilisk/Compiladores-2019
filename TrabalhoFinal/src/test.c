
#include<stdio.h>
#include<stdlib.h>
#include<utils.h>
#include<parser.h>

int main(int argc, char *argv[]){
    char *line = readLine(stdin, '\n');
    printf("%s\n",line);
    free(line);
    return 0;
}
