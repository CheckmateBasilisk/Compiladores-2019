/**@<main.c>::**/
#include <stdio.h>
#include <stdlib.h>
/*
 * to be compiled with -I. C-flag 
 */
#include <tokens.h>
#include <parser.h>

int             gettoken(FILE *);

FILE           *source,
               *object;

int
main(int argc, char *argv[])
{
    int             token;
    source = stdin;
    object = stdout;

    lookahead = gettoken(source);

    expr();

    exit(0);
}
