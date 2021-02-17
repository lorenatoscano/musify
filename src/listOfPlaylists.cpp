#include <iostream>
#include "listOfPlaylists.h"

using namespace std;

/** Inicializa head e tail com valores nulos e o tamanho com 0 */
ListOfPlaylists::ListOfPlaylists() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

/** Desaloca os nós da lista caso ainda existam na memória */
ListOfPlaylists::~ListOfPlaylists() {
  if (size != 0) {
    node_* temp = nullptr;
    node_* cur = nullptr;

    cur = head;

    while (cur != nullptr) {
      temp = cur->next;
      delete cur;
      cur = temp;
    }
  }
}

size_t ListOfPlaylists::getSize() {
  return size;
}

/**
 * Cria e insere no fim da lista um nó que armazena aa playlist passada por argumento
 * @param value ponteiro para objeto do tipo Playlist.
 */
void ListOfPlaylists::insertPlaylist(Playlist* value) {
  node_* temp = new node_;

  temp->data = value;
  temp->next = nullptr;

  if (head == nullptr) {
    head =  temp;
    tail = temp;
    temp = nullptr;
  } else {
    tail->next = temp;
    tail = temp;
  }

  ++size;
}

/**
 * Deleta o nó da posição escolhida e recria o link entre seu antecessor e sucessor.
 * Faz o tratamento caso a posição escolhida seja a primeira ou maior que a última.
 * @param pos índice da posição escolhida (a partir de 1)
 */
void ListOfPlaylists::removePlaylist(size_t pos) {
  node_* pre = nullptr;
  node_* cur = nullptr;

  cur = head;

  if (pos == 1) {
    head = head->next;
  } else if (pos <= size) {
    for (size_t i = 1; i < pos; ++i) {
      pre = cur;
      cur = cur->next;
    }
    
    pre->next = cur->next;
  } else {
    while (cur->next != nullptr) {
      pre = cur;
      cur = cur->next;
    }

    tail = pre;
    pre->next = nullptr;
  }

  --size;
  delete cur->data;
  delete cur;
}

/**
 * Exibe as playlists armazenadas na lista ligada
 */
void ListOfPlaylists::display() {
  node_* temp = head;
  size_t index = 1;
  string name = "";

  while (temp != nullptr) {
    name = temp->data->getName();
    cout << index << " - " << name << endl;
    temp = temp->next;
    ++index;
  }
}