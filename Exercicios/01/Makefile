# our first Makefile to build our first parser

CFLAGS=-g -I.

expr: main.o lexer.o parser.o
#	$(CC) -o expr main.o lexer.o parser.o
	$(CC) -o $@ $^

clean:
	$(RM) *.o

mostlyclean: clean
	$(RM) *~

indent:
	/usr/bin/indent -bap -ts4 -nut -orig lexer.c main.c parser.c parser.h tokens.h
