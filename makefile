all: main.o linkedSongs.o library.o
	gcc -o output linkedSongs.o main.o library.o

main.o: main.c linkedSongs.h
	gcc -c main.c

linkedSongs.o: linkedSongs.c
	gcc -c linkedSongs.c

library.o: library.c library.h
	gcc -c library.c

run:
	./output

clean:
	rm *.o
	rm output
