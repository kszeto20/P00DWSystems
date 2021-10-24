#include "linkedSongs.h"
#include <stdlib.h>
#include <stdio.h>


int main () {
  printf("Good News Everyone\n");

  char name1[] = "Viva La Vida";
  char artist1[] = "Coldplay";
  struct song_info *one = songCreation(name1, artist1);

  printSong(one);
}
