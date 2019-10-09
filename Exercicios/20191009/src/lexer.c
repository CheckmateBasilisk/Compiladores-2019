#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#include<utils.h>
#include<lexer.h>

/**
lexer deals with the lexic layer of the project
    - checking if a number is written appropratelly, for instance
    
Defines the available tokens    

**/

//skips all spaces at the head of tape
void skipSpaces(FILE * tape){
    int head;
    while (isspace(head = getc(tape)));
    ungetc(head, tape);
}

//returns TRUE if the following characters in tape are an ID
BOOLEAN isID(FILE * tape) {
    int head;
    TOKEN pattern = 0;

    if (isalpha(head = getc(tape))) {
        while (isalnum(head = getc(tape)));
        pattern = TRUE;
    }
    ungetc(head, tape);

    return pattern;
}

//returns TRUE if the following characters in tape are a DEC
BOOLEAN isDEC(FILE *tape){
    int head;
    if (isdigit(head = getc(tape))) {
        // check if zero '0' 
        if (head == '0') {
            return TRUE;
        }
        //otherwise, it is [1-9] 

        //do [0-9]* 
        while (isdigit(head = getc(tape)));

        //emulate epsilon transition: 
        ungetc(head, tape);
            return TRUE;
    }
    ungetc(head, tape);

    return FALSE;
}

BOOLEAN isEXIT(FILE *tape){
    int c;
    if('e' == (c=fgetc(tape)))
    if('x' == (c=fgetc(tape)))
    if('i' == (c=fgetc(tape)))
    if('t' == (c=fgetc(tape)))
        return TRUE;

    return FALSE;
}

//eats the head of tape and returns TRUE if it matches expected
//returns FALSE otherwise
BOOLEAN match(int expected, FILE *tape){
    char head = fgetc(tape);
    
    if(head == expected){
        return TRUE;
    } else {
        fprintf(stderr, "%c met while %c was expected\n", head, expected);
        return FALSE;
    }
}

//recognizes and returns a TOKEN from head of tape
//UNRECOGNIZED is a token to represent an unrecognized token
TOKEN getToken(FILE *tape){
    // TOKEN token = UNRECOGNIZED;

    skipSpaces(tape);
    if (isEXIT(tape) == TRUE)//checks if it is an exit before checking if it is an ID
        return EXIT;
    if (isID(tape) == TRUE )
        return ID;
    if (isDEC(tape) == TRUE)
        return DEC;

    //TODO : should return the invalid token?
    //token = getc(source);

    return UNRECOGNIZED;
}
