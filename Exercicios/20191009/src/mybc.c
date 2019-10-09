#include<stdio.h>
#include<stdlib.h>

#include<ctype.h>
#include<mybc.h>

MACHINE startEnvironment(FILE *input, FILE *output){
    MACHINE m;

    m.input = input;
    m.output = output;
    m.tStack = 0;
    m.tStackSize = 0;

    return m;
}
