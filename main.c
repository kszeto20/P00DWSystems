#include "linkedSongs.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
  printf("LINKED LIST TESTS\n====================================\n\n");

  struct song_node *front = NULL;
  front = insert_song(front, "ac/dc", "thunderstruck");
  front = insert_song(front, "pink floyd", "time");
  front = insert_song(front, "pearl jam", "even flow");
  front = insert_song(front, "pearl jam", "yellow ledbetter");
  front = insert_song(front, "pearl jam", "alive");
  front = insert_song(front, "radiohead", "street spirit (fade out)");
  front = insert_song(front, "radiohead", "paranoid android");

  printf("Testing print_list\n");
  print_list(front);
  printf("\n====================================\n\n");

  printf("Testing print_song:\n");
  print_song(front);
  printf("\n====================================\n\n");

  printf("Testing insert front: \n");
  front = insert_song(front, "the rolling stones", "paint it black");
  print_list(front);
  printf("====================================\n\n");

  printf("Testing insert front: \n");
  front = insert_front(front, "the rolling stones", "paint it black");
  print_list(front);
  printf("====================================\n\n");

  printf("Testing find node: \n");
  find_node(front, "pearl jam", "even flow");
  find_node(front, "mura masa", "love$ick");
  printf("====================================\n\n");

  printf("Testing find artist: \n");
  find_artist(front, "pearl jam");
  find_artist(front, "playboi carti");
  printf("====================================\n\n");

  printf("Testing random:\n");
  print_song(random_song(front));
  printf("\n");

  print_song(random_song(front));
  printf("\n");

  printf("====================================\n\n");
  printf("Testing remove:\n");
  front = remove_song(front, "pearl jam", "alive");
  print_list(front);
  front = remove_song(front, "pearl jam", "yellow ledbetter");
  print_list(front);
  front = remove_song(front, "pink floyd", "alive");
  print_list(front);
  printf("====================================\n\n");

  printf("Testing free_list:\n");
  front = free_list(front);
  printf("list after free_list: ");
  print_list(front);
  printf("====================================\n\n");
  return 0;
}
