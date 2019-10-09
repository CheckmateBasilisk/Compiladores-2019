#include<stdio.h>
#include<lexer.h>
#include<parser.h>
#include<mybc.h>

int main(int argc, char *argv[]){
    MACHINE environment;
    environment = startEnvironment(stdin,stdout);

    printf("tokens recognized:\n");

    while(! feof(input)){
        TOKEN token = getToken(input);

        if(token == DEC) {
            printf("dec ");
        } else if(token == ID){
            printf("id ");
        } else if(token == EXIT){
            printf("exit");
            break;
        } else if(token == UNRECOGNIZED){
            printf("unrecognized ");
        }

    }

    puts("");


    return 0;
}
