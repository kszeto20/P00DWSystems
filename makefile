all: main.o linkedSongs.o library.o
	gcc -o output linkedSongs.o library.o main.o

main.o: main.c linkedSongs.h library.h
	gcc -c main.c

linkedSongs.o: linkedSongs.c
	gcc -c linkedSongs.c

library.o: library.c
	gcc -c library.c


run:
	./output

clean:
	rm *.o
	rm output
