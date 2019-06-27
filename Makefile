all: clean
	flex scanner.lex
	bison -v -d parser.ypp
	g++ -g -o hw5 *.c *.cpp
clean:
	rm -f lex.yy.c
	rm -f parser.tab.*pp
	rm -f hw5