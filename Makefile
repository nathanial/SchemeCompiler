CC = g++ -Wall -Werror -I/Users/nathan/Sources/boost_1_42_0/


run : build
	./interp

parser.o : parser.cpp parser.hpp
	$(CC) -c parser.cpp

token.o : token.cpp token.hpp
	$(CC) -c token.cpp

lexer.o : lexer.rl token.o
	ragel lexer.rl
	mv lexer.c lexer.cpp
	$(CC) -c lexer.cpp

build : main.cpp lexer.o parser.o token.o
	$(CC) parser.o lexer.o token.o main.cpp -o interp

clean : 
	rm -f *.o
	rm -f *.~
	rm -f ./lexer.c
	rm ./interp
