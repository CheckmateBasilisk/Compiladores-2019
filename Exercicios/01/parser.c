/**@<parser.c>::**/
#include <parser.h>

/**************************************************************
 * parser for a simplified arithmetic expression
 * Method: emulates a LL(1) parser tree with the replacing of
 * non-terminal symbols in the left by 
 * 	void symbol(void), 
 * and right non-terminal symbols by their corresponding 
 * procedure/function call. 
 *
 * LL(1) grammar: 
 * initial symbol: expr
 * 
 * expr -> term rest
 *
 * 	expr =>* <term> <rest> EOF
 * 	expr =>* <term> <rest> ')'
 *
 * 	FOLLOW (expr) = FOLLOW (rest) = { EOF, ')' }
 * 
 * term -> fact quoc 
 *
 * 	FOLLOW(quoc) = FOLLOW(term) = { EOF, ')', '+', '-' }
 *
 * fact -> ID 
 * 	 | DEC 
 * 	 | '(' expr ')' 
 *
 * quoc -> '*' fact quoc 
 * 	 | '/' fact quoc 
 * 	 | <epsilon> 
 *
 * rest -> '+' term rest 
 * 	 | '-' term rest 
 * 	 | <epsilon> 
 *
 *************************************************************/

void
expr(void)
{
    term();
    rest();
}

void
term(void)
{
    fact();
    quoc();
}

int             lookahead;
void
fact(void)
{
    switch (lookahead) {
    case ID:
        match(ID);
        break;
    case UINT:
        match(UINT);
        break;
    case FLT:
        match(FLT);
        break;
    default:
        match('(');
        expr();
        match(')');
    }
}

void
quoc(void)
{
    switch (lookahead) {
    case '*':
    case '/':
        match(lookahead);
        fact();
        quoc();
        break;
    case EOF:
    case ')':
    case '+':
    case '-':
        /*
         * FOLLOW(quoc) = FOLLOW(term) = { EOF, ')', '+', '-' } 
         */
        ;
    default:
        fprintf(stderr,
                "invalid trailing token: %d\nexiting with error status %d\n",
                lookahead, -3);
        exit(-3);
    }
}

void
rest(void)
{
    switch (lookahead) {
    case '+':
    case '-':
        match(lookahead);
        term();
        rest();
        break;
    case EOF:
    case ')':
        /*
         * if lookahead in FOLLOW (rest) = { EOF, ')' }, then * rest ->
         * <epsilon> * else * report error of following symbol / token *
         * endif 
         */
        ;
    default:
        fprintf(stderr,
                "invalid trailing token: %d\nexiting with error status %d\n",
                lookahead, -3);
        exit(-3);
    }
}

/*
 * lexer-to-parser interface: 
 */

void
match(int expected)
{
    if (lookahead == expected) {
        lookahead = gettoken(source);
    } else {
        fprintf(stderr,
                "%d seen while %d expected\n", lookahead, expected);
        exit(-2);
    }
}
