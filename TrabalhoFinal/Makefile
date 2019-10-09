INCLUDE = ./src/utils.c ./src/parser.c

all:
	gcc -o ./build/main ./src/main.c $(INCLUDE) -I./include -Wall

run:
	./build/main

test:
	gcc -o ./build/test ./src/test.c $(INCLUDE) -I./include -Wall


runtest:
	./build/test
