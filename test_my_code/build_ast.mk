CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/print_canonical

parser/test_parser.tab.cpp parser/test_parser.tab.hpp : parser/test_parser.y
	bison -v -d parser/test_parser.y -o parser/test_parser.tab.cpp

lex/test_lexer.yy.cpp : lex/test_lexer.flex parser/test_parser.tab.hpp
	flex -o lex/test_lexer.yy.cpp  lex/test_lexer.flex

bin/print_canonical : parser/print_canonical.o parser/test_parser.tab.o lex/test_lexer.yy.o parser/test_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/print_canonical $^




clean :
	rm parser/*.o
	rm lex/*.o
	rm bin/*
	rm parser/*.tab.cpp
	rm lex/*.tab.cpp
	rm parser/*.yy.cpp
	rm lex/*.yy.cpp
	rm parser/test_parser.output
	rm parser/tset_parser.tab.hpp
