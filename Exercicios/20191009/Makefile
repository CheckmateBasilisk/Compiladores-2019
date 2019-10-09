INCLUDE =  ./src/lexer.c ./src/parser.c ./src/mybc.c
INCLUDEDIR  = ./include
BUILDDIR  = ./build

all:
	gcc -o $(BUILDDIR)/main ./src/main.c $(INCLUDE)  -I$(INCLUDEDIR) -Wall

run:
	$(BUILDDIR)/main

test:
	gcc -o $(BUILDDIR)/test ./src/test.c $(INCLUDE) -I$(INCLUDEDIR) -Wall

runtest:
	$(BUILDDIR)/test
