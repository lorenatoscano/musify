#include <iostream>
#include "linkedList.h"
#include "song.h"
#include "utils.h"

using namespace std;

/** Inicializa head e tail com valores nulos e o tamanho com 0 */
LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

/** Desaloca os nós da lista caso ainda existam na memória */
LinkedList::~LinkedList() {
  if (size != 0) {
    node* temp = nullptr;
    node* cur = nullptr;

    cur = head;

    while (cur != nullptr) {
      temp = cur->next;
      delete cur;
      cur = temp;
    }
  }
}

node* LinkedList::getHead() {
  return head;
}

size_t LinkedList::getSize() {
  return size;
}

/**
 * Cria e insere no início da lista um nó que armazena a música passada por argumento
 * @param value objeto do tipo Song.
 */
void LinkedList::insertStart(Song value) {
  // Evita a adição de músicas repetidas
  if (search(value) != nullptr) {
    cout << "A música já existe no sistema." << endl;
  } else {
    node* temp = new node;

    temp->data = value;
    temp->next = head;
    head = temp;

    ++size;
  }
}

/**
 * Cria e insere no fim da lista um nó que armazena a música passada por argumento
 * @param value objeto do tipo Song.
 */
void LinkedList::insertEnd(Song value) {
  // Evita a adição de músicas repetidas
  if (search(value) != nullptr) {
    cout << "A música já existe no sistema." << endl;
  } else {
    node* temp = new node;

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
}

/**
 * Cria e insere numa posição escolhida um nó que armazena a música passada por argumento.
 * Faz o tratamento caso a posição escolhida seja a primeira ou maior que a última.
 * @param pos índice da posição escolhida (a partir de 1)
 * @param value objeto do tipo Song.
 */
void LinkedList::insertPosition(size_t pos, Song value) {
  node* pre = nullptr;
  node* cur = nullptr;

  if (pos == 1) {
    insertStart(value);
  } else if (pos <= size) {
    // Evita a adição de músicas repetidas
    if (search(value) != nullptr) {
      cout << "A música já existe no sistema." << endl;
    } else {

      node* temp = new node;
      
      cur = head;
    
      for (size_t i = 1; i < pos; ++i) {
        pre = cur;
        cur = cur->next;
      }

      temp->data = value;
      pre->next = temp;
      temp->next = cur;

      ++size;
    }
  } else {
    insertEnd(value);
  }
}

/**
 * Declara o segundo elemento da lista como head e deleta o primeiro
 */
void LinkedList::removeFirst() {
  node* temp = head;

  head = head->next;

  --size;
  delete temp;
}

/**
 * Declara o penúltimo elemento da lista como tail e deleta o ultimo
 */ 
void LinkedList::removeLast() {
  node* pre = nullptr;
  node* cur = nullptr;

  cur = head;

  while (cur->next != nullptr) {
    pre = cur;
    cur = cur->next;
  }

  tail = pre;
  pre->next = nullptr;

  --size;
  delete cur;
}

/**
 * Deleta o nó da posição escolhida e recria o link entre seu antecessor e sucessor.
 * Faz o tratamento caso a posição escolhida seja a primeira ou maior que a última.
 * @param pos índice da posição escolhida (a partir de 1)
 */
void LinkedList::removePosition(size_t pos) {
  node* pre = nullptr;
  node* cur = nullptr;

  if (pos == 1) {
    removeFirst();
  } else if (pos <= size) {
    cur = head;

    for (size_t i = 1; i < pos; ++i) {
      pre = cur;
      cur = cur->next;
    }
    
    pre->next = cur->next;

    --size;
    delete cur;
  } else {
    removeLast();
  }
}

/**
 * Percorre a lista procurando o nó que contenha os mesmos valores da música passada por parâmetro. Desconsidera maíusculas.
 * @param searchSong música a ser buscada
 * @return o ponteiro para o nó, caso a busca tenha sucesso, ou nullptr caso contrário.
 */
node* LinkedList::search(Song searchSong) {
  node* temp = head;

  while (temp != nullptr) {
    Song s = temp->data;

    // Compara os títulos e artistas desconsiderando maiúsculas
    if ( toLowercase(s.getTitle()) == toLowercase(searchSong.getTitle()) && 
        toLowercase(s.getArtist()) == toLowercase(searchSong.getArtist()) ) {
      // Retorna o ponteiro para o nó correspondente
      return temp; 
    }

    temp = temp->next;
  }
  // Caso não encontre, retorna nullptr
  return nullptr;
}

/**
 * Percorre a lista até a posição passada por parâmetro e obtém o nó correspondente.
 * @param pos índice da posição escolhida (a partir de 1)
 * @return o ponteiro para o nó, caso a posição esteja dentro do tamanho da lista, ou nullptr caso contrário.
 */
node*LinkedList::getNode(size_t pos) {
  // Caso a posição seja inválida, retorna nullptr
  if (pos < 1 || pos > size) {
    return nullptr;
  } else {
    node* temp = head;

    for (size_t i = 1; i < pos; ++i) {
      temp = temp->next;
    }
    // Retorna o ponteiro para o nó correspondente
    return temp;
  }
}


/**
 * Exibe as músicas armazenadas na lista ligada
 */
void LinkedList::display() {
  node* temp = head;
  size_t index = 1;

  while (temp != nullptr) {
    Song s = temp->data;
    cout << index << " - " << s.getTitle() << " - " << s.getArtist() << endl;
    temp = temp->next;
    ++index;
  }
}