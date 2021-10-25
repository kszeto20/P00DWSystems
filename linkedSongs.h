#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct song_info {
  char name[100];
  char artist[100];
  struct song_info *next;
};

//insert nodes at the front (done)
struct song_info * insert_front(struct song_info *first,  char *name, char *artist);

// make nodes
struct song_info * songCreation(char *n, char *a);

// compare two songs
int comp(struct song_info *x, struct song_info *y);
// insert helper
struct song_info * insert (struct song_info *front, struct song_info *toComp);
// add in alpha order
struct song_info * insert_song (struct song_info *front, char *a, char *n);

// print the entire list (done)
void print_list(struct song_info *first);

// print member (by search to be implmented)
void print_node(struct song_info * p);

// free member (by search to be implemented)
struct song_info * remove_node(struct song_info *front, int data);

// free the entire list
struct song_info * free_list(struct song_info * toFree);

// Return a pointer to random element in the list (done)
struct song_info * random_song (struct song_info * toFree);

// find by artist then name
int data_check(struct song_info *a, char *artist, char *name);
struct song_info * find_node(struct song_info *front, char *artist, char *name);

struct song_info * find_artist(struct song_info *front, char *artist);
/*
remove a single specified node from the list
specified by both artist and song name.

*/
