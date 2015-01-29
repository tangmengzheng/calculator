cal:cal.o seqStack.o tools.o trance.o
	gcc -o cal cal.o seqStack.o tools.o trance.o
cal.o:cal.c 
	gcc -c cal.c 
seqStack.o:seqStack.c seqStack.h
	gcc -c seqStack.c
tools.o:tools.c tools.h
	gcc -c tools.c
tranc.o:trance.c trance.h
	gcc -c trance.c
clean:
	rm cal.o seqStack.o tools.o trance.o
