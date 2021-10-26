#include "linkedSongs.h"
#include <stdlib.h>
#include <stdio.h>

void print_song(struct song_node *node) {
  if (node) {
    printf("{%s: %s} ", node->artist, node->name);
  }
}
void print_list(struct song_node *front) {
  while(front) {
    print_song(front);
    front = front->next;
  }
  printf("\n");
}

struct song_node * songCreation(char *n, char *a) {
  struct song_node *new = malloc(sizeof(struct song_node));

  new->name = n;
  new->artist = a;
  new->next = NULL;

  return new;
}


struct song_node * insert_front(struct song_node *front, char *n, char *a) {
  struct song_node *new = songCreation(n, a);
  new->next = front;
  return new;
}

int songCmp(struct song_node *x, struct song_node *y) {
  if (strcasecmp(x->artist, y->artist) >= 0) {
    return (strcasecmp(x->name, y->name) == 1);
  }
  else {
    return 0;
  }
}

struct song_node * insert(struct song_node *front, struct song_node *toAdd) {
  if (front == NULL) {
    return toAdd;
  }
  else if (songCmp(front, toAdd)) {
    toAdd->next = front;
    return toAdd;
  }
  struct song_node *before = front;
  while (before->next) {
    if (songCmp(before->next, toAdd)) {
      toAdd->next = before->next;
      before->next = toAdd;
      return front;
    }
    else {
      before = before->next;
    }
  }
  before->next = toAdd;
  return front;
}

struct song_node * insert_song(struct song_node *front, char *artist, char *name) {
  struct song_node *toIns = songCreation(name, artist);
  front = insert(front, toIns);
  return front;
}

struct song_node * find_node(struct song_node *front, char *artist, char *name) {
    printf("Looking for %s by %s\n", name, artist);
    struct song_node *temp = front;
    while (temp) {
        if (data_check(temp, name, artist)) {
          printf("Song Found: ");
          print_song(temp);
          printf("\n");
          return temp;
        }
        else temp = temp->next;
    }
    printf("\nsong not found\n");
    return NULL;
}

struct song_node * find_artist(struct song_node *front, char *artist) {
  printf("Looking for songs by %s\n", artist);
  struct song_node *temp = front;
  while (temp) {
      if (strcasecmp(temp->artist, artist) == 0) {
        printf("Artist Found: ");
        print_song(temp);
        printf("\n");
        return temp;
      }
      else temp = temp->next;
  }
  printf("\nartist not found\n");
  return NULL;
}

struct song_node * random_song (struct song_node * toFree) {
  struct song_node *front = toFree;
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

int data_check(struct song_node *a, char *name, char *artist) {
  if (strcasecmp(a->artist, artist) == 0) {
    if (strcasecmp(a->name, name) == 0) {
      return 1;
    }
  }
  return 0;
}

struct song_node * remove_song(struct song_node *front, char *artist, char *name) {
  printf("Removing: %s by %s\n", name, artist);
  if (data_check(front, name, artist)) {
    front = front->next;
  }
  struct song_node *before = front;
  struct song_node *temp = front->next;
  while (temp) {
    if (data_check(temp, name, artist)) {
      before->next = temp->next;
      return front;
    }
    else {
      before = before->next;
      temp = temp->next;
    }
  }
  printf("Song not found");
  return front;
}

struct song_node * free_list(struct song_node *first) {
  while(first != NULL) {
    struct song_node *nToFree = first->next;
    printf("freeing node: {%s by %s}\n", first->artist, first->name);
    free(first);
    first = nToFree;
  }
  return first;
}
