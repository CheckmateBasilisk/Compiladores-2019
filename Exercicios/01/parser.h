/**@<parser.h>::**/
/*
 * grammar initial symbol: expr 
 */
#pragma once

void            expr(void);
/*
 */
void            term(void);
void            rest(void);
void            fact(void);
void            quoc(void);
void            match(int);
extern int      lookahead;
#include <tokens.h>
#include <stdio.h>
#include <stdlib.h>
extern FILE    *source,
               *object;
int             gettoken(FILE *);
