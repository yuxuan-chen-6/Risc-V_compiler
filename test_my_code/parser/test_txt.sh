bison -v -d test_parser.y -o test_parser.tab.cpp 

g++ -c test_parser.tab.cpp

#生成lexer.yy.cpp
flex -o lexer.yy.cpp lexer.flex
#生成lexer.o
g++ -c lexer.yy.cpp -o lexer.o


g++ test_parser.tab.o lexer.o -o parser


./parser < input.txt
