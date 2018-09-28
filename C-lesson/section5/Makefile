GOC = gcc
CFLAGS = -Wall -O2

genrand: genrand.c
	${GOC} ${CELAGS} -c -o $@ $< 

getdist.o: getdist.c
mylib.o: mylib.c
	${GOC} ${CELAGS} -c -o $@ $< -lm

getdist: getdist.o mylib.o
	${GOC} ${CELAGS} -o $@ $^ -lm



clean:
	rm -f *~ *.o