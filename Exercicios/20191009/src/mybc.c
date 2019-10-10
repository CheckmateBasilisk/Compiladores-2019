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

//evaluates (and solves) an expression
//evaluates whats in the input inside machine
int expr(MACHINE *machine){
    
    // + - preceeding expr


    //else if lookahead == DEC
    if(m->lookahead == DEC){
        
        //acc <- converted lexeme
        //match(DEC) //will work and advance fp


    //else if lookahead == VAR or ID (cant remember now)
    } else if(m->lookahead == ID){
        //read variale and add it to symtable
            //move forward with fp in the process
        //if lookahead = ':=' (ASSIGNMENT)
            //RECURSIVELY CALL EXPR
            // set value of variale to the return of expr at the symtable
    //else if lookahead == (
    } else if(m->lookahead == '('){
        //match (
        //RECURSIVELY CALL EXPR
        //match )
    //if flagOtimes != 0
        // * or / acc and top of stack
        // pop top of stack
        //acc holds the result (is this correct?)
    //if flagOplus != 0
        // + or - acc and top of stack
        // pop top of stack
        //acc holds the result (is this correct?)
    } else {
        //throw error message 
    }

    return 0;
}

//stores a symbol at the symtable and its respective value
void store(char *name, int value, MACHINE *m){
}
//returns the value of a given symbol name from symtable
int recall(char *name, MACHINE *m){
    return value;
}
