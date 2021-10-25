#include "linkedSongs.h"
#include <stdlib.h>
#include <stdio.h>


int main () {
  printf("Good News Everyone\n");

  char sep[] = "----------------------------\n";

  char name[] = "DNA.";
  char artist[] = "Kendrick Lamar";

  struct song_info *one = songCreation(name, artist);
/*
  print_node(one);

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

  printf("%s", sep);

  print_list(five);

  printf("%s", sep);

  struct song_info *left = random_song(five);
  print_node(left);

  printf("%s", sep);
*/
  char name1[] = "Viva La Vida";
  char artist1[] = "Coldplay";

  char name2[] = "Light It Up";
  char artist2[] = "Major Lazer";

  char name3[] = "In My Feelings";
  char artist3[] = "Drake";

  char name4[] = "City of Stars";
  char artist4[] = "La La Land Cast";


  struct song_info *addedIn = insert_song(one, name1, artist1);
  addedIn = insert_song(addedIn, name2, artist2);
  addedIn = insert_song(addedIn, name3, artist3);
  addedIn = insert_song(addedIn, name4, artist4);

  print_list(addedIn);
}
