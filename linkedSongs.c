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

int songcmp(struct song_info *x, struct song_info *y) {
  if (strcasecmp(x->artist, y->artist) >= 0) {
    return (strcasecmp(x->name, y->name));
  } else {
    return 0;
  }
}

struct song_info * insert (struct song_info *front, struct song_info *toComp) {
  if (front == NULL) {
    return toComp;
  }
  if (songcmp(front, toComp)) {
    toComp->next = front;
    return toComp;
  }
  struct song_info *before = front;
  struct song_info *curr = front->next;
  while (curr) {
    if (songcmp(curr, toComp)) {
      toComp->next = curr;
      before->next = toComp;
      return front;
    }
    else {
      curr = curr->next;
      before = before->next;
    }
  }
  before->next = toComp;
  return front;
}

struct song_info * insert_song (struct song_info *front, char *a, char *n) {
  struct song_info *toAdd = songCreation(a, n);
  if (front == NULL) {
    return toAdd;
  }
  if (songcmp(front, toAdd)) {
    toAdd->next = front;
    return toAdd;
  }
  struct song_info *before = front;
  struct song_info *curr = front->next;
  while (curr) {
    if (songcmp(curr, toAdd)) {
      toAdd->next = curr;
      before->next = toAdd;
      return front;
    }
    else {
      curr = curr->next;
      before = before->next;
    }
  }
  before->next = toAdd;
  return front;
}

struct song_info * random_song (struct song_info * toFree) {
  struct song_info *front = toFree;
  int count = 0;
  while(toFree != NULL) {
    count += 1;
    toFree = toFree -> next;
  }

  toFree = front;
  srand(time(NULL));
  int x = (rand() % count);
  //printf("%d", x);

  for (int i = 0; i < x; i++) {
    toFree = toFree->next;
  }
  return toFree;
}

// Returns true if node contains given data
int data_check(struct song_info *a, char *artist, char *name) {
  if (strcasecmp(a->artist, artist) == 0) {
    if (strcasecmp(a->name, name) == 0) {
      return 1;
    }
  }
  return 0;
}

// finds a given node in the list
struct song_info * find_node(struct song_info *front, char *artist, char *name) {
    printf("looking for %s by %s\n", name, artist);
    struct song_info *temp = front;
    while (temp) {
        if (data_check(temp, artist, name)) {
          printf("Song Found: ");
          print_node(temp);
          printf("\n");
          return temp;
        }
        else temp = temp->next;
    }
    printf("\tsong not found\n");
    return NULL;
}

void print_node(struct song_info * p) {
  printf("The song is %s by %s\n", p->name, p->artist);
}

void print_list(struct song_info *first) {
  while (first != NULL) {
    print_node(first);
    first = first->next;
  }
}
