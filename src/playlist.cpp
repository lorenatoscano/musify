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