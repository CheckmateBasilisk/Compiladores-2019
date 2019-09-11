/**@<lexer.c>::**/

/*
 * Author: Eraldo Pereira Marinho, PhD Creation Date: Wed Aug 14 14:37:22
 * -03 2019 
 */

/**************************************************************
 * Lexical analyser for a modified / simplified Pascal, aka
 * MyPas (mypas)
 *************************************************************/

/*
 * int isID abstracts the following NFA: [A-Za-z0-9] ----------- | |
 * [A-Za-z] v | isID: --->( )---------->( )-------- | | | |<epsilon> |
 * ----------->( ) |<epsilon> ----------->( ) [A-Za-z] == isalpha(head);
 * [A-Za-z0-9] == isalnum(head); <epsilon> == ungetc(head, tape); 
 */

#include <stdio.h>
#include <ctype.h>

void
skipspaces(FILE * tape)
{
    int             head;
    while (isspace(head = getc(tape)));
    ungetc(head, tape);
}

#include <tokens.h>

int
isID(FILE * tape)
{
    int             head;
    int             pattern = 0;

    if (isalpha(head = getc(tape))) {
        while (isalnum(head = getc(tape)));   
        pattern = ID;
    }
    ungetc(head, tape);
    return pattern;
}

int isNUM(FILE * input){
    input = stdin;
    int c;
    
    c = getc(input);
    if(c == EOF || c == ENTER) return 0;
    if(c == '0'){ // if input starts with '0'
        int c = getc(input);
        if(c == EOF || c == ENTER){
            return UINT;
        } else if(c == '.'){ // 0 followed by '.'
            int c;
            do{
                c = getc(input);
            }while(isdigit(c));
 
            if((c == 'e') || (c == 'E')){    //0. folloed by [eE]
                c = getc(input);
                if(c == EOF || c == ENTER){
                    return -1;
                }
                if((c == '+') || (c == '-')){
                    c = getc(input);
                    if(c == EOF || c == ENTER){
                        return -1;
                    }
                }

                while(isdigit(c)){
                    c = getc(input);    //check if c belongs to [0-9]*
                }

                if(c == EOF || c == ENTER){
                    return FLT;
                }else {
                    return -1;
                }
            }
            
            if(c == EOF || c == ENTER){
                return FLT; 
            }
            return -1;// 0. followed by anything else than EOF || c == ENTER
        } else if(c == 'e'||'E'){ // 0 followed by [eE]
            c = getc(input);
            if(c == EOF || c == ENTER){
                return -1;
            }
            if((c == '+') || (c == '-')){
                c = getc(input);
                if(c == EOF || c == ENTER){
                    return -1;
                }
            }

            while(isdigit(c)){
                c = getc(input);    //check if c belongs to [0-9]*
            }

            if(c == EOF || c == ENTER){
                return FLT;
            }else {
                return -1;
            }
            return -1;  //if input does not match 0|[1-9]+|[eE]|'.' => error
        }else { // 0 followed by anything else
            return -1;  //if first character is a 0 followed by anything else => error
        }

    } else if(isdigit(c)){ //if input starts with [1-9]  .Passing previous if guarantees it doesnt start with '0'

        do{
            c = getc(input);    //check if c belongs to [0-9]*
        }while(isdigit(c));


        if(c == EOF || c == ENTER){
            return UINT;
        }else if(c == '.'){
            do{
                c =(getc(input));   //check if c belongs to [0-9]*
            }while(isdigit(c));

            if(c == EOF || c == ENTER){   //if input is [1-9] [0-9]* followed by EOF || c == ENTER
                return FLT;
            }else           //if input is [1-9] [0-9]* followed by anything else => error
                return -1;
        

        } else if((c == 'e') || (c == 'E')){    //if input is [1-9][0-9]* followed by [eE] 
            c = getc(input);
            if(c == EOF || c == ENTER){
                return -1;
            }
            if((c == '+') || (c == '-')){
                c = getc(input);
                if(c == EOF || c == ENTER){
                    return -1;
                }
            }

            while(isdigit(c)){
                c = getc(input);    //check if c belongs to [0-9]*
            }
            if(c == EOF || c == ENTER){
                return FLT;
            }else {
                return -1;
            }
        }else{
            return -1;  //if input is [1-9] followed by anything else => error
        }
        
    } else if(c == '.'){    //if input starts with '.'
        c = getc(input);
        if(c == EOF || c == ENTER)    //if input is '.' followed by nothing => error
            return -1;
        
        while(isdigit(c))
            c = (getc(input));
    
        if(c == EOF || c == ENTER){   //if input is '.' [0-9]+
            return FLT;
        }else if((c == 'e') || (c == 'E')){   //if input is '.' [0-9] [eE]
            c = getc(input);
            if(c == EOF || c == ENTER){
                return -1;
            }
            if((c == '+') || (c == '-')){
                c = getc(input);
                if(c == EOF || c == ENTER){
                    return -1;
                }
            }

            while(isdigit(c)){
                c = getc(input);    //check if c belongs to [0-9]*
            }


            if(c == EOF || c == ENTER){
                return FLT;
            }else {
                return -1;
            }
            
        }else
            return -1;  //if input is '.' [0-9]+ followed by anything that is not digit => error
    
    } else if((c == 'e') || (c == 'E')){    //if input starts with [eE]
        c = getc(input);
        if(c == EOF || c == ENTER){
            return -1;
        }
        if((c == '+') || (c == '-')){
            c = getc(input);
            if(c == EOF || c == ENTER){
                return -1;
            }
        }

        while(isdigit(c)){
            c = getc(input);    //check if c belongs to [0-9]*
        }


        if(c == EOF || c == ENTER){
            return FLT;
        }else {
            return -1;
        }
        
    }else
        return -1;  //if input does not match 0|[1-9]+|[eE]|'.' => error
}


/*
int
isDEC(FILE * tape)
{
    int             head;

    if (isdigit(head = getc(tape))) {
        
         * check if zero '0' 
         
        if (head == '0') {
            return DEC;
        }
        
         * otherwise, it is [1-9] 
         

        
         * do [0-9]* 
         
        while (isdigit(head = getc(tape)));

        
         * emulate epsilon transition: 
         
        ungetc(head, tape);
        return DEC;
    }
    ungetc(head, tape);
    return 0;
}
*/

/*
 * lexer-to-parser interface 
 */

int
gettoken(FILE * source)
{
    int             token;

    skipspaces(source);

    if (token = isID(source))
        return token;
    if (token = isNUM(source))
        return token;

    token = getc(source);

    return token;
}
