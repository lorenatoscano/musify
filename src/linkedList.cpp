#include <iostream>
#include "linkedList.h"
#include "song.h"

using namespace std;

/** Inicializa head e tail com valores nulos */
LinkedList::LinkedList() {
  head = NULL;
  tail = NULL;
}

LinkedList::~LinkedList() {
}

/**
 * Cria um nó que armazena a música passada por argumento
 * @param value objeto do tipo Song.
 */
void LinkedList::createNode(Song value) {
  node* temp = new node;
  temp->data = value;
  temp->next = NULL;

  if (head == NULL) {
    head =  temp;
    tail = temp;
    temp = NULL;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

/**
 * Exibe as músicas armazenadas na lista ligada
 */
void LinkedList::display() {
  node* temp = new node;
  temp = head;

  while (temp != NULL) {
    Song s = temp->data;
    cout << s.getTitle() << " - " << s.getArtist() << endl;
    temp = temp->next;
  }
}