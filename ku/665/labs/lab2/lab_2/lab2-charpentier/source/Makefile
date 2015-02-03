LEX=lex
CC=gcc

LFLAGS=
CFLAGS=-Wall -Wno-unused-label -Wno-unused -g

all: reg_expr

reg_expr: reg_expr.lex.o
	$(CC) -o $@ $+

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.lex.c: %.l
	$(LEX) $(LFLAGS) -o $@ $< 

test_qstat:
	./reg_expr < qstat_output.txt > test_qstat.txt

test_java:
	./reg_expr < java.cpp > test_java.cpp

clean:
	$(RM) *.o
	$(RM) *.lex.c
	$(RM) reg_expr

.PHONY: clean all test_qstat test_java
