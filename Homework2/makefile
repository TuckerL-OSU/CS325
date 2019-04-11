CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: stoogesort.c stoogeTime.c
	gcc -o stoogesort stoogesort.c $(CFLAGS)
	gcc -o stoogeTime stoogeTime.c $(CFLAGS)

clean:
	rm -f stoogesort stooge.out stoogeTime