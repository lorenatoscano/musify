#include <iostream>

#include "song.h"
#include "linkedList.h"

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
  
  queue->insertEnd(*s1);
  queue->insertStart(*s2);
  queue->insertPosition(2, *s3);

  queue->display();

  delete s1;
  delete s2;
  delete s3;
  delete queue;

  return 0;
}
