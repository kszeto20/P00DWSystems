all: main.o linkedSongs.o
	gcc -o output linkedSongs.o main.o

linkedSongs.o: linkedSongs.c
	gcc -c linkedSongs.c

run:
	./output

clean:
	rm *.o
	rm output
