all: programa limpa

programa: main.o string_soma.o
	gcc main.o string_soma.o -o exec

main.o: main.c string_soma.c string_soma.h
	gcc -c main.c

string_soma.o: string_soma.c string_soma.h
	gcc -c string_soma.c

limpa: 
	rm *.o