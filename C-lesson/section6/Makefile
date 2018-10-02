GOC = gcc
CFLAGS = -Wall -O2

1-a: 1-a.c
	${GOC} ${CELAGS} -o $@ $< -lm

getdist2.o: getdist2.c
mylib.o: mylib.c
	${GOC} ${CELAGS} -c -o $@ $< -lm

getdist2: getdist2.o mylib.o
	${GOC} ${CELAGS} -o $@ $^ -lm
clean:
	rm -f *~ *.o