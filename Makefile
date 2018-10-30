all: T1ED

T1ED: main.o funcoes.o estruturas.o
	gcc -o T1ED main.o funcoes.o estruturas.o -lm

estruturas.o: estruturas.c
	gcc -o estruturas.o -c estruturas.c -g -Wall

funcoes.o: funcoes.c
	gcc -o funcoes.o -c funcoes.c -g -Wall

main.o: main.c funcoes.h estruturas.h
	gcc -o main.o -c main.c -g -Wall

clean:
	rm -f *.o T1ED
