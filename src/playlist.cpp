#include "playlist.h"

using namespace std;

/** Aloca a lista de músicas e inicializa atributos */
Playlist::Playlist() {
  songs = new LinkedList;
  playing = nullptr;
  count = 1;
}

/** Libera a memória da lista de músicas */
Playlist::~Playlist() {
  delete songs;
}

LinkedList* Playlist::getSongs() {
  return songs;
}

string Playlist::getName() {
  return name;
}

void Playlist::setName(string _name) {
  name = _name;
}

/**
 * Chama o método da lista para inserir a música na playlist de acordo com a posição.
 * @param pos índice da posição escolhida (a partir de 1)
 * @param value objeto do tipo Song.
 */
void Playlist::insertSong(size_t pos, Song value) {
  songs->insertPosition(pos, value);
  // Cada vez que uma nova música for inserida, playing recebe head
  playing = songs->getHead();
}

/**
 * Chama o método da lista para remover uma música da playlist de acordo com a posição.
 * @param pos índice da posição escolhida (a partir de 1)
 */
void Playlist::removeSong(size_t pos) {
  songs->removePosition(pos);
}

/**
 * Move uma música de acordo com as posições passadas por parâmetro
 * @param start índice da posição inicial da música
 * @param end índice da posição final desejada
 */
void Playlist::moveSong(size_t start, size_t end) {
  if (start != end) {
    // Acessa o valor da música a ser movida
    node* target = songs->getNode(start);
    Song value = target->data;

    // Remove ela da posição atual
    songs->removePosition(start);

    // Insere ela na nova posição
    if (end < start) {
      songs->insertPosition(end, value);
    } else {
      songs->insertPosition(end + 1, value);
    } 

    // Cada vez que uma música for movida, playing recebe head
    playing = songs->getHead();
  }
}

/**
 * Versão sobrecarregada do método de inserção, que insere na playlist atual todas as músicas da playlist passada por argumento.
 * @param toInsert referência de um objeto do tipo playlist
 */
void Playlist::insertSong(Playlist& toInsert) {
  // Tratamento para garantir que a nova lista não está vazia
  if (toInsert.getSongs()->getSize() < 1) {
    return;
  } else {
    // Insere as músicas na playlist atual por meio de sobrecarga
    songs->insertEnd(*toInsert.getSongs());
  }
}

/**
 * Versão sobrecarregada do método de remoção, que remove da playlist atual todas as músicas da playlist passada por parâmetro.
 * @param toRemove referência de um objeto do tipo playlist
 * @return quantidade de elementos removidos
 */
size_t Playlist::removeSong(Playlist& toRemove) {
  // Tratamento para garantir que a nova playlist não está vazia
  if (toRemove.getSongs()->getSize() < 1) {
    return 0;
  } else {
    size_t removed = 0;

    node* temp = toRemove.getSongs()->getHead();

    while (temp != nullptr) {
      // Obtém a posição da música na playlist atual
      size_t pos = getSongs()->getPosition(temp->data);

      // Remove da playlist atual
      if (pos > 0) {
        removeSong(pos);
        ++removed;
      }

      temp = temp->next;
    }
    
    return removed;
  }
}


/**
 * Retorna a música a ser tocada e incrementa a que está "tocando" para a próxima
 * @return o ponteiro da música a ser tocada, ou nullptr caso não tenha mais músicas
 */
node* Playlist::playNext() {
  if (playing != nullptr) {
    // Guarda a música atual
    node* temp = playing;
    // Playing recebe a próxima música
    playing = playing->next;
    // Retorna a atual a ser tocada
    return temp;
  } 
  // Retorna nullptr caso não tenha mais nenhuma a tocar
  return nullptr;
}

/**
 * Função recursiva que imprime todas as músicas que formam a playlist
 * @param current ponteiro para o nó atual contendo a música a ser impressa
 */
void Playlist::displayAllSongs(node* current) {
  // Condição de parada
  if (current == nullptr) {
    count = 1;
    return;
  }
  // Imprime a música atual
  cout << count << " - " << current->data.getTitle() << " - " << current->data.getArtist() << endl;
  ++count;
  // Chamada recursiva
  displayAllSongs(current->next);
}