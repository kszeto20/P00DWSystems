#include "library.h"

struct song_node ** libraryCreation() {
    struct song_node (*library)[27] = calloc(27, sizeof(struct song_node *));
    return library;
}

struct song_node ** add_song(struct song_node ** library, char *artist, char *name) {
  int lowered = tolower(artist[0]) - 97;
  if (lowered > 25 || lowered < 0) {
    library[26] = insert_song(library[26], artist, name);
  }
  else {
    library[lowered] = insert_song(library[lowered], artist, name);
  }
  return library;
}



void print_library (struct song_node **library) {
  int i;
  for (i = 0; i < 27; i++) {
    if (listLen(library[i]) > 0) {
      if (i != 26) {
        printf("%c: \t", 97 + i);
      } else {
        printf("special: \t");
      }
      print_list(library[i]);
    }
  }
}

void print_letter (struct song_node **library, char let) {
  int lowered = let - 97;
  if (lowered > 25 || lowered < 0) {
    print_list(library[26]);
  }
  else {
    print_list(library[lowered]);
  }
}

int listLen(struct song_node *list) {
  int counter = 0;
  while (list != NULL) {
    counter += 1;
    list = list->next;
  }
  return counter;
}

struct song_node * find_song_lib(struct song_node ** library, char *artist, char *name) {
  int lowered = tolower(artist[0]) - 97;
  if (lowered > 25 || lowered < 0) {
    return find_node(library[26], artist, name);
  }
  else {
    return find_node(library[lowered], artist, name);
  }
}
// checks for artist existence
struct song_node * find_artist_lib(struct song_node ** library, char *artist) {
  int lowered = tolower(artist[0]) - 97;
  if (lowered > 25 || lowered < 0) {
    return find_artist(library[26], artist);
  }
  else {
    return find_artist(library[lowered], artist);
  }
}
// prints all of the artist's songs
void print_artist_lib (struct song_node ** library, char * artist) {
  struct song_node *first = find_artist_lib(library, artist);
    while (first != NULL && first->artist == artist) {
        print_song(first);
        first = first->next;
    }
    printf("\n");
}

struct songs ** remove_song_lib(struct song_node ** library, char *artist, char *name) {
  printf("Removing: [%s. %s]\n", artist, name);
  int lowered = tolower(artist[0]) - 97;
  if (lowered > 25 || lowered < 0) {
    library[26] = remove_song(library[26], artist, name);
  }
  else {
    library[lowered] = remove_song(library[lowered], artist, name);
  }
  return library;
}

void shuffle_lib(struct song_node **library) {

  srand(time(NULL));

  int i;
  int a = 27;

  int num_songs = 0;
  int pCount = 0;

  while (num_songs < 3) {
    for (i = 0; i < 27; i++) {
      a = a + rand();
      a = a % 27;

      if (listLen(library[a]) == 0) {
        continue;
      }
      if (pCount < 3) {
        print_song(random_song(library[a]));
        pCount += 1;
      }
      num_songs++;
    }
  }
}

struct song_node ** free_library(struct song_node **library) {
    int counter;
    for (counter = 0; counter < 27; counter++) {
        library[counter] = free_list(library[counter]);
    }
    return library;
}
