#include <iostream>

#include "song.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Song* s1 = new Song;
  Song* s2 = new Song;
  LinkedList* queue = new LinkedList;

  s1->setTitle("New Rules");
  s1->setArtist("Dua Lipa");

  s2->setTitle("Paradise");
  s2->setArtist("Coldplay");

  queue->createNode(*s1);
  queue->createNode(*s2);

  queue->display();

  delete s1;
  delete queue;

  return 0;
}
