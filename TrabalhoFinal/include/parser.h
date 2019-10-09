
#ifndef _PARSER_H_
#define _PARSER_H_

/*-------LIBRARIES-------*/
#include<stdio.h>
/*-------DEFINES-------*/
/*-------TYPES-------*/
typedef enum{
    UNDEFINED = -1,
    NONE = 0,

    UINT = 1024,//arbitrary 
    FLOAT,
    ID
}TOKEN;
/*-------HEADERS-------*/
TOKEN parseToken(FILE *input);

#endif
