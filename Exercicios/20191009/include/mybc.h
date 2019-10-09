
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

    TOKEN *tStack;//stack of tokens
    int tStackSize;//size of the Token Stack

    SYMBOL *symTable;//table of symbols: variables and their values
                //implemented as a dynamically allocated array of structs
    int symTableSize;//size of the SymTable 
}MACHINE;

/******headers******/

#endif
