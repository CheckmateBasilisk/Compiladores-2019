
#ifndef _LEXER_H_
#define _LEXER_H_

/******includes******/
#include<utils.h>
#include<lexer.h>
/******defines******/
/******types******/
//TOKENS are extensions of the ascii table. Chars are also tokens, but might not have much meaning on their own
typedef enum {
    ID = 1024,
    DEC,
    //OPLUS,
    //OTIMES,
    ASSIGNMENT, //marks an assignment in progress
            //':=' ==> ASSIGNMENT
    EXIT,
    UNRECOGNIZED //invalid token
}TOKEN;

/******headers******/
TOKEN getToken(FILE *);
int match(int , FILE *);

#endif
