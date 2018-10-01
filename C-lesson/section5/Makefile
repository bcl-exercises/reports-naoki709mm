GOC = gcc
CFLAGS = -Wall -O2

mylib2: mylib2.c
genrand: genrand.c
	${GOC} ${CELAGS} -c -o $@ $< 

getdist.o: getdist.c
getdist_x.o: getdist.c
mylib.o: mylib.c
	${GOC} ${CELAGS} -c -o $@ $< -lm

getdist: getdist.o mylib.o
	${GOC} ${CELAGS} -o $@ $^ -lm	
getdist_x: getdist_x.o mylib.o
	${GOC} ${CELAGS} -o $@ $^ -lm



clean:
	rm -f *~ *.o