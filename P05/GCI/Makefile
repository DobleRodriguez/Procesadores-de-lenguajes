


Analizador\ Semántico: Analizador\ Semántico.tab.c lex.yy.c
	gcc  -g lex.yy.c  Analizador\ Semántico.c Analizador\ Semántico.tab.c -o parser

Analizador\ Semántico.tab.c: Analizador\ Semántico.y 
	bison -v -d Analizador\ Semántico.y

lex.yy.c: Analizador\ Léxico.l
	flex Analizador\ Léxico.l

all:
	make Analizador\ Semántico

clean:
	@echo ""
	@echo Limpiando los ficheros...
	@echo ""
	rm -f *.yy.c *.tab.c *.tab.h *.output semantic
	@echo ""
	@echo Limpieza finalizada
	@echo ""

ejecuta:
	./parser mainp2.bbaaa