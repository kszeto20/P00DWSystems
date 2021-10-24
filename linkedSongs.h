#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct song_info {
  char name[100];
  char artist[100];
  struct song_info *next;
};

//insert nodes at the front
struct song_info * insert_front(struct song_info *first,  char *name, char *artist);

// make nodes (in order to be implemented later)
struct song_info * songCreation(char *n, char *a);

// print the entire list
void print_list(struct song_info *first);

// print member (by search to be implmented)
void printSong(struct song_info * p);

// free member (by search to be implemented)
struct song_info * remove_node(struct song_info *front, int data);

// free the entire list
struct song_info * free_list(struct song_info * toFree);

/*

insert nodes in order
alphabetical by Artist then by Song
you should have a helper function to compare song nodes effectively.

find and return a pointer to a node based on artist and song name
find and return a pointer to the first song of an artist based on artist name
Return a pointer to random element in the list.
remove a single specified node from the list
specified by both artist and song name.

*/
