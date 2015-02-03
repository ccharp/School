LEX=lex
YACC=yacc
CC=gcc

LFLAGS=
CFLAGS=-Wall -Wno-unused-label -Wno-unused -g

all: lexer 

lab4: lexer.lex.o
	$(CC) -o $@ $+

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.lex.c: %.l
	$(LEX) $(LFLAGS) -o $@ $<

%.tex: %.c lexer 
	./lexer < $< > $@
	
%.pdf: %.tex
	pdflatex $<

test: lexer test.c

clean:
	$(RM) *.o
	$(RM) *.lex.c
	$(RM) *.tex *.log *.aux *.pdf
	$(RM) lexer 

.PHONY: clean all test
