#ifndef MY_LISTS
#define MY_LISTS "linkedSongs"

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

struct song_node {
    char *name;
    char *artist;
    struct song_node *next;
};

void print_song(struct song_node *node); //done

void print_list(struct song_node *front); //done

struct song_node * songCreation(char *name, char *artist); // done

int songCmp(struct song_node *a, struct song_node *b); // done

struct song_node * insert(struct song_node *front, struct song_node *node); //done

struct song_node * insert_song(struct song_node *front, char *name, char *artist); // done

struct song_node * insert_front(struct song_node *front, char *name, char *artist); // done

int data_check(struct song_node *a, char *name, char *artist);

struct song_node * find_node(struct song_node *front, char *artist, char *name); // done

struct song_node * find_artist(struct song_node *front, char *artist); // done

struct song_node * random_song(struct song_node *toFree); // done

struct song_node * free_list(struct song_node *front);

struct song_node * remove_song(struct song_node *front, char *artist, char *name);

#endif
