#include "linkedSongs.h"
#include <stdlib.h>
#include <stdio.h>

// make nodes (in order to be implemented later)
struct song_info * songCreation(char *n, char *a) {
  struct song_info *newP = malloc(sizeof(struct song_info));
  strcpy(newP->name, n);
  strcpy(newP->artist, a);
  // newP->name = strcpy(n);
  // newP->artist = strcpy(a);
  newP->next = NULL;
  return newP;
}

struct song_info * insert_front(struct song_info *first,  char *name, char *artist) {
  struct song_info *new = songCreation(name, artist);
  new->next = first;
  return new;
}

void printSong(struct song_info * p) {
  printf("The song is %s by %s\n", p->name, p->artist);
}

void print_list(struct song_info *first) {
  while (first != NULL) {
    printSong(first);
    first = first->next;
  }
}
