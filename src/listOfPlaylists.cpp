#include <iostream>
#include "listOfPlaylists.h"
#include "utils.h"

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
      delete cur->data;
      delete cur;
      cur = temp;
    }
  }
}

size_t ListOfPlaylists::getSize() {
  return size;
}

/**
 * Percorre a lista até a posição passada por parâmetro e obtém o ponteiro da playlist correspondente.
 * @param pos índice da posição escolhida (a partir de 1)
 * @return o ponteiro para a playlist, caso a posição esteja dentro do tamanho da lista, ou nullptr caso contrário.
 */
Playlist* ListOfPlaylists::getPlaylist(size_t pos) {
  // Caso a posição seja inválida, retorna nullptr
  if (pos < 1 || pos > size) {
    return nullptr;
  } else {
    node_* temp = head;

    for (size_t i = 1; i < pos; ++i) {
      temp = temp->next;
    }
    // Retorna o ponteiro para a playlist correspondente
    return temp->data;
  }
}

/**
 * Percorre a lista procurando a playlist com o mesmo nome passado por parâmetro e obtém o ponteiro correspondente. Desconsidera maíusculas.
 * @param searchName playlist a ser buscada
 * @return o ponteiro para a playlist, caso a busca tenha sucesso, ou nullptr caso contrário.
 */
Playlist* ListOfPlaylists::searchPlaylist(string searchName) {
  node_* temp = head;

  while (temp != nullptr) {
    // Compara os nomes desconsiderando maiúsculas
    if ( toLowercase(temp->data->getName()) == toLowercase(searchName) ) {
      // Retorna o ponteiro para o nó correspondente
      return temp->data; 
    }

    temp = temp->next;
  }
  // Caso não encontre, retorna nullptr
  return nullptr;
}



/**
 * Cria e insere no fim da lista um nó que armazena aa playlist passada por argumento
 * @param value ponteiro para objeto do tipo Playlist.
 */
void ListOfPlaylists::insertPlaylist(Playlist* value) {
  if (searchPlaylist(value->getName()) != nullptr) {
    cout << "Já existe uma playlist com esse nome no sistema." << endl;
  } else {
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
    cout << "Playlist criada! Adicione algumas músicas." << endl;
  }
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
  } else if (pos < size) {
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
 * Percorre todas as playlists do sistema e remove delas a música passada por parâmetro.
 * @param target objeto do tipo Song com a música a ser removida
 */
void ListOfPlaylists::removeFromAll(Song target) {
  node_* temp = head;

  // Percorre as playlists do sistema
  while (temp != nullptr) {
    // Guarda a lista de músicas atual
    LinkedList* songs = temp->data->getSongs();

    // Verifica se o alvo está na lista 
    if (songs->search(target) != nullptr) {
      // Obtém a posição numérica da música
      size_t pos = songs->getPosition(target);
      // Remove a música da lista
      songs->removePosition(pos);
    }

    temp = temp->next;
  }
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


