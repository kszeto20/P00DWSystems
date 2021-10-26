#ifndef MY_LIB
#define MY_LIB "libSet"

#include "linkedSongs.h"
#include <stdlib.h>
#include <stdio.h>

struct song_node ** libraryCreation(); // done
struct song_node ** add_song(struct song_node ** library, char *artist, char *name); // done
int listLen(struct song_node *list); // done
void print_library (struct song_node **library); // done
void print_letter (struct song_node **library, char let); // done
struct song_node * find_song_lib(struct song_node ** library, char *artist, char *name); //done
struct song_node * find_artist_lib(struct song_node ** library, char *artist); // done
void print_artist_lib (struct song_node ** library, char * artists); // done
struct songs ** remove_song_lib(struct song_node ** library, char *artist, char *name); // done
void shuffle_lib(struct song_node **library);

/*

Shuffle - print out a series of randomly chosen songs.
Clear out all the linked lists in the library.
*/

#endif
