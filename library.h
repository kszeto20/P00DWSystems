#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "linkedSongs.h"

struct info_info ** create_library();

struct song_info  ** add_song_lib (struct song_info **library, char *name, char *artist);

struct song_info  ** find_song_lib (struct song_info **library, char *name, char *artist);

struct song_info ** find_art_lib (struct song_into **library, char *name, char *artist);

void print_l_lib (struct song_into **library, char *let);
