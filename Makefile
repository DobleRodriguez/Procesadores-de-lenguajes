


syntactic: syntactic.tab.c lex.yy.c
	gcc lex.yy.c syntactic.tab.c -o syntactic

syntactic.tab.c: syntactic.y 
	bison -v -d  syntactic.y

lex.yy.c: lexicon.l
	flex lexicon.l

all:
	make syntactic

clean:
	@echo ""
	@echo Limpiando los ficheros...
	@echo ""
	rm -f *.c *.h *.output
	@echo ""
	@echo Limpieza finalizada
	@echo ""

ejecuta:

	./syntactic main.bbaaa