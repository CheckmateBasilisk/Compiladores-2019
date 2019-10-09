
#ifndef _LEXER_H_
#define _LEXER_H_

/******includes******/
#include<utils.h>
#include<lexer.h>
/******defines******/
/******types******/
typedef enum {
    ID = 1024,
    DEC,
    //OPLUS,
    //OTIMES,
    EXIT,
    UNRECOGNIZED //invalid token
}TOKEN;

/******headers******/
TOKEN getToken(FILE *);

#endif
