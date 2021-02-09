#include <iostream>

#include "song.h"
#include "linkedList.h"
#include "utils.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Song* s1 = new Song;
  Song* s2 = new Song;
  Song* s3 = new Song;

  LinkedList* queue = new LinkedList;

  s1->setTitle("New Rules");
  s1->setArtist("Dua Lipa");

  s2->setTitle("Paradise");
  s2->setArtist("Coldplay");

  s3->setTitle("Musica 3");
  s3->setArtist("Artista 3");
  
  queue->insertPosition(2, *s1);
  queue->insertPosition(1, *s2);
  queue->insertPosition(2, *s3);

  queue->display();

  queue->removePosition(2);

  cout << endl;
  queue->display();

  Song searchSong;
  searchSong.setArtist("Dua Lipa");
  searchSong.setTitle("NeW Rules");
  node* result = queue->search(searchSong);
  cout << result << endl;

  string antes = "LoREnA";
  string depois = toLowercase(antes);
  cout << antes << " - " << depois << endl;

  delete s1;
  delete s2;
  delete s3;

  delete queue;

  return 0;
}
