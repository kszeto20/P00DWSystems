#include "library.h"

struct info_info ** create_library() {
  struct song_node (*library)[27] = malloc(27, sizeof(struct song_info));
  return library;
}

struct song_info  ** add_song_lib (struct song_info **library, char *name, char *artist) {
  // add song struct
  if (tolower(artist[0]) - 97 > 25 || tolower(artist[0]) - 97 < 0) {
    library[26]= insert_song(library[26], name, artist);
  }
  else {
    //alpha range
    library[tolower(artist[0]) - 97] = insert_song(library[tolower(artist[0]) - 97], name, artist);
  }
  return library;
}

struct song_info ** find_song_lib (struct song_into **library, char *name, char *artist) {
  if (tolower()artist[0] - 97 > 25 || tolower(artist[0]) - 97 < 0) {
    return find_song(library[26], name, artist);
  }
  else {
    return find_song(library[tolower(artist[0]) - 97], name, artist);
  }
}

struct song_info ** find_art_lib (struct song_into **library, char *name, char *artist) {
  if (tolower()artist[0] - 97 > 25 || tolower(artist[0]) - 97 < 0) {
    return find_artist(library[26], name, artist);
  }
  else {
    return find_artist(library[tolower(artist[0]) - 97], name, artist);
  }
}

void print_l_lib (struct song_into **library, char *let) {
  if (let - 97 > 25 || let - 97 < 0) {
    print_list(library[26]);
  }
  else {
    print_list(library[let -97]);
  }
}
