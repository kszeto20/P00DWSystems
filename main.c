#include "linkedSongs.h"
#include <stdlib.h>
#include <stdio.h>


int main () {
  printf("Good News Everyone\n");

  char sep[] = "----------------------------\n";
  printf("%s", sep);

  printf("Testing Print Node Printing:\n");
  char name[] = "DNA";
  char artist[] = "Kendrick Lamar";

  struct song_info *one = songCreation(name, artist);
  print_node(one);
  printf("%s", sep);

  //////////////////////

  printf("Testing Print List:\n");
  char name2[] = "In My Feelings";
  char artist2[] = "Drake";
  struct song_info *two = insert_front(one, name2, artist2);

  char name3[] = "City of Stars";
  char artist3[] = "La La Land Cast";
  struct song_info *three = insert_front(two, name3, artist3);

  char name4[] = "Light it Up";
  char artist4[] = "Major Lazer";
  struct song_info *four = insert_front(three, name4, artist4);

  char name5[] = "DNA.";
  char artist5[] = "Kendrick Lamar";
  struct song_info *five = insert_front(four, name5, artist5);
  print_list(five);

  printf("%s", sep);

  printf("Testing Random Node Generator\n");
  struct song_info *left = random_song(five);
  print_node(left);

  printf("%s", sep);


  char tname1[] = "Viva La Vida";
  char tartist1[] = "Coldplay";

  char tname2[] = "Light It Up";
  char tartist2[] = "Major Lazer";

  char tname3[] = "In My Feelings";
  char tartist3[] = "Drake";

  char tname4[] = "City of Stars";
  char tartist4[] = "La La Land Cast";

  char tname5[] = "Marvin's Room";
  char tartist5[] = "Drake";


  struct song_info *addedIn = insert_song(one, tname1, tartist1);
  addedIn = insert_song(addedIn, tname2, tartist2);
  addedIn = insert_song(addedIn, tname3, tartist3);
  addedIn = insert_song(addedIn, tname4, tartist4);
  addedIn = insert_song(addedIn, tname5, tartist5);
  print_list(addedIn);

  printf("%s", sep);

  printf("Testing find node\n");
  struct song_info *nodeFound = find_node(addedIn, "Kendrick Lamar", "DNA");
  print_node(nodeFound);

  printf("%s", sep);

  printf("Testing find node\n");
  find_artist(addedIn, "Kendrick Lamar");

}
