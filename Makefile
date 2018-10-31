all: T1ED

T1ED: main.o funcoes.o estruturas.o
	gcc -o -T1ED main.o funcoes.o estruturas.o -lm -std=gnu99 

estruturas.o: estruturas.c
	gcc -o estruturas.o -c estruturas.c -g -Wall -std=gnu99 

funcoes.o: funcoes.c
	gcc -o funcoes.o -c funcoes.c -g -Wall -std=gnu99 

main.o: main.c funcoes.h estruturas.h
	gcc -o main.o -c main.c -g -Wall -std=gnu99 

clean:
	rm -f *.o T1ED
