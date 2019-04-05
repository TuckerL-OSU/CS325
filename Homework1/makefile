CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: mergesort.c insertsort.c mergeTime.c insertTime.c
	gcc -o mergesort mergesort.c $(CFLAGS)
	gcc -o insertsort insertsort.c $(CFLAGS)
	gcc -o mergeTime mergeTime.c $(CFLAGS)
	gcc -o insertTime insertTime.c $(CFLAGS)

clean:
	rm -f mergesort merge.txt insertsort insertsort.txt mergeTime insertTime