
all:    parser
 
parser:	mylang.tab.c  lex.yy.c TablaSimbolos.cpp Quad.cpp
	g++ -std=c++14 -o parser mylang.tab.c lex.yy.c TablaSimbolos.cpp Quad.cpp MapaMemoria.cpp -ly -ll 

lex.yy.c:	mylang.l
	flex mylang.l

mylang.tab.c:	mylang.y
	bison -vd mylang.y
