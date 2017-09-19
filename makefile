CFLAGS = -Wall
CC = gcc

prog: a4.o sort.o string.o
	${CC} ${CFLAGS} -o prog a4.o sort.o string.o

a4.o: a4.c a4.h

sort.o: sort.c a4.h

string.o: string.c a4.h

clean:
	rm *.o prog