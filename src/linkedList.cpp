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

/** Copia todos os elementos da lista passada por referência para a lista atual 
 * @param oldList referência de objeto do tipo linkedList.
*/
LinkedList::LinkedList(const LinkedList& oldList) {
  head = nullptr;
  tail = nullptr;
  size = 0;

  node* temp = oldList.head;

  while (temp != nullptr) {
    insertEnd(temp->data);

    temp = temp->next;
  }
}

/** Concatena a lista atual com a lista passada por referência e retorna uma lista final
 * @param secondList referência de objeto do tipo linkedList.
 * @return a lista final concatenada.
*/
LinkedList LinkedList::operator+ (const LinkedList& secondList) {
  LinkedList finalList;

  // Percorre a lista atual copiando os valores para a lista final
  node* temp = head;
  while (temp != nullptr) {
    finalList.insertEnd(temp->data);

    temp = temp->next;
  }
  
  // Percorre a segunda lista copiando os valores para a lista final
  temp = secondList.head;
  while (temp != nullptr) {
    node* newNode = new node;

    newNode->data = temp->data;
    newNode->next = nullptr;
    
    if (finalList.head == nullptr) {
      finalList.head = newNode;
      finalList.tail = newNode;
      newNode = nullptr;
    } else {
      finalList.tail->next = newNode;
      finalList.tail = newNode;
    }

    finalList.size++;
    temp = temp->next;
  }
  
  return finalList;
}

/** Extrai o último elemento da lista atribuindo seus valores ao nó recebido como argumento
 * @param lastNode recebe os valores do nó extraído.
*/
void LinkedList::operator>> (node*& lastNode){ 
  if (size > 0) {
    lastNode->data = tail->data;
    lastNode->next = tail->next;

    removeLast();
  } else {
    lastNode = nullptr;
  }
}

/** Insere um nó passado por argumento no fim da lista
 * @param newNode nó a ser inserido.
*/
void LinkedList::operator<< (node*& newNode) {
  if (newNode == nullptr) {
    return;
  } else {
    insertEnd(newNode->data);
  }
}

node* LinkedList::getHead() {
  return head;
}

node* LinkedList::getTail() {
  return tail;
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
 * Versão sobrecarregada do método de inserção, que insere na lista atual todos os elementos da lista passada por argumento.
 * @param toInsert referência de um objeto do tipo lista ligada
 */
void LinkedList::insertEnd(LinkedList& toInsert) {
  // Tratamento para garantir que a nova lista não está vazia
  if (toInsert.getSize() < 1) {
    return;
  } else {
    node* temp = toInsert.getHead();

    while (temp != nullptr) {
      // Insere cada elemento no fim da lista atual
      insertEnd(temp->data);
      
      temp = temp->next;
    }
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
    if (size == 0) {
      insertEnd(value);
    } else {
      insertStart(value);
    } 
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
  } else if (pos < size) {
    cur = head;

    for (size_t i = 1; i < pos; ++i) {
      pre = cur;
      cur = cur->next;
    }
    
    pre->next = cur->next;

    --size;
    delete cur;
  } else if (pos < 1) {
    return;
  } else {
    removeLast();
  }
}

/**
 * Versão sobrecarregada do método de remoção, que remove da lista atual todos os elementos da lista passada por parâmetro.
 * @param toRemove de um objeto do tipo lista ligada
 */
void LinkedList::removePosition(LinkedList& toRemove) {
  // Tratamento para garantir que a nova lista não está vazia
  if (toRemove.getSize() < 1) {
    return;
  } else {
    node* temp = toRemove.getHead();

    while (temp != nullptr) {
      // Obtém a posição da música na lista atual
      size_t pos = getPosition(temp->data);
  
      // Remove da lista atual
      if (pos > 0) {
        removePosition(pos);
      }                      
      
      temp = temp->next;
    }    
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
node* LinkedList::getNode(size_t pos) {
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
 * Percorre a lista até encontrar a música passada por parâmetro e obtém a posição correspondente.
 * @param searchSong música a ser buscada
 * @return a posição na lista, caso a busca tenha sucesso, ou 0 caso contrário
 */
size_t LinkedList::getPosition(Song searchSong) {
  node* temp = head;
  size_t pos = 1;

  while (temp != nullptr) {
    Song s = temp->data;

    // Compara os títulos e artistas desconsiderando maiúsculas
    if ( toLowercase(s.getTitle()) == toLowercase(searchSong.getTitle()) && 
        toLowercase(s.getArtist()) == toLowercase(searchSong.getArtist()) ) {
      // Retorna a posição correspondente
      return pos; 
    }

    temp = temp->next;
    ++pos;
  }
  // Caso não encontre, retorna 0
  return 0;
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