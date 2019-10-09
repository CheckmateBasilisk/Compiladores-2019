#include<stdio.h>
#include<ctype.h>
#include<utils.h>
#include<parser.h>

/**
Parser is responsible for parsing the inputfile for the Tokens
**/

//global variable, keeping track of the top of the tape
//updated whenever getc is called
int lookahead;

//returns TRUE if there's a Num at tape
//consumes the top of tape
//if FALSE, ungets things 
BOOLEAN isNum(FILE *tape){
    BOOLEAN boolean = FALSE;

    

    return boolean;
}

//returns TRUE if there's a Float at tape
//if FALSE, ungets things 
BOOLEAN isFloat(FILE *tape){

    return FALSE;    
}

//returns TRUE if there's an Id at the tape
//if FALSE, ungets things 
BOOLEAN isId(FILE *tape){

    return FALSE;    
}

//returns TRUE if reached end of tape
BOOLEAN isEmpty(FILE *tape){
    if(lookahead == EOF) return TRUE;
    else return FALSE;
}

//checks if lookahead == c
//if not, returns FALSE and ungets
BOOLEAN match(int c, FILE *tape){
    int c2 = getc(tape);
    if(lookahead == c2){//if matches
        return TRUE;
    }else{
        ungetc(c2,tape);
        return FALSE;
    }
}
//returns the top token in the tape
//returns UNDEFINED if token is not recognized
//returns NONE if there's no token at the tape
TOKEN parseToken(FILE *tape){
    //TOKEN token = 0;
    if(isNum(tape)){
        return UINT;
    } else if(isFloat(tape)){
        return FLOAT;
    } else if(isId(tape)){
        return ID;
    } else if(isEmpty(tape)){
        return NONE;
    }
    
    return UNDEFINED;
}

