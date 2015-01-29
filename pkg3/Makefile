cal:cal.o tools.o
	gcc -o cal cal.o tools.o
cal.o:cal.c cal.h
	gcc -c cal.c
tools.o:tools.c tools.h
	gcc -c tools.c
clean:
	rm cal.o tools.o

