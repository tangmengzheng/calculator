cal:cal.o	seqStack.o tools.o
	gcc -o cal cal.o seqStack.o tools.o
cal.o:cal.c
	gcc -c cal.c
tools.o:tools.c tools.h
	gcc -c tools.c
seqStack.o:seqStack.c  seqStack.h
	gcc -c seqStack.c
clean:
	rm cal.o seqStack.o tools.o

