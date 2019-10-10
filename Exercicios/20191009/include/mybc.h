
#ifndef _MYBC_H_
#define _MYBC_H_

/******includes******/
#include<stdio.h>
#include<lexer.h>
#include<parser.h>
/******defines******/
/******types******/
//symbol is an entry in symTable, identifying a declared identifier
typedef struct SYMBOL{
    char *name;
    int value;
}SYMBOL;

//MACHINE abstracts the environment in which mybc runs on
//  it has the input and output files
typedef struct MACHINE{
    FILE *input;
    FILE *output;

    TOKEN flagOtimes; // if == 0 nothing is set
    TOKEN flagOplus;  // if == 0 nothing is set
    TOKEN flagSignal; // keeps track if an expression should or not be mult. by -1
    
    int acc;//accumulator for the value of an expression in evalation

    TOKEN lookahead; //keeps track of which token is coming ahead in input
    char *lexeme;//keeps track of the content of a given token
        //for instance, a DEC might have a value of '10' (which will be converted to (int) afterwards during evaluation)

    int *stack;//stack of values from lexemes 
    int stackSize;//size of the Token Stack

    SYMBOL *symTable;//table of symbols: variables and their values
                //implemented as a dynamically allocated array of structs
    int symTableSize;//size of the SymTable 
}MACHINE;

/******headers******/
MACHINE startEnvironment(FILE *, FILE *);
int recall(char *, MACHINE *);
void store(char *, int , MACHINE *);

#endif
