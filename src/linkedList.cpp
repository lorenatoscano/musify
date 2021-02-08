#include <iostream>
#include "linkedList.h"
#include "song.h"

using namespace std;

/** Inicializa head e tail com valores nulos e o tamanho com 0 */
LinkedList::LinkedList() {
  head = NULL;
  tail = NULL;
  size = 0;
}

LinkedList::~LinkedList() {
}

/**
 * Cria um nó que armazena a música passada por argumento
 * @param value objeto do tipo Song.
 */
void LinkedList::createNode(Song value) {
  node* temp = nullptr;

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
 * Cria e insere no início da lista um nó que armazena a música passada por argumento
 * @param value objeto do tipo Song.
 */
void LinkedList::insertStart(Song value) {
  node* temp = new node;

  temp->data = value;
  temp->next = head;
  head = temp;

  ++size;
}

/**
 * Cria e insere no fim da lista um nó que armazena a música passada por argumento
 * @param value objeto do tipo Song.
 */
void LinkedList::insertEnd(Song value) {
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

  ++size;
}

/**
 * Cria e insere numa posição escolhida um nó que armazena a música passada por argumento
 * @param pos índice da posição escolhida (a partir de 1)
 * @param value objeto do tipo Song.
 */
void LinkedList::insertPosition(size_t pos, Song value) {
  node* pre = new node;
  node* cur = new node;
  node* temp = new node;

  if (pos == 1) {
    insertStart(value);
  } else if (pos <= size) {
    cur = head;
  
    for (size_t i = 1; i < pos; ++i) {
      pre = cur;
      cur = cur->next;
    }

    temp->data = value;
    pre->next = temp;
    temp->next = cur;

    ++size;
  } else {
    insertEnd(value);
  }

  // delete(pre);
  // delete(cur);
  // delete(temp);
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