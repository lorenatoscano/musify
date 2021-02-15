#include "playlist.h"

using namespace std;

/** Aloca a lista de músicas e inicializa a que está "tocando" com o valor de head */
Playlist::Playlist() {
  songs = new LinkedList;
  playing = songs->getHead();
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
}

/**
 * Chama o método da lista para remover uma música da playlist de acordo com a posição.
 * @param pos índice da posição escolhida (a partir de 1)
 */
void Playlist::removeSong(size_t pos) {
  songs->removePosition(pos);
}

/**
 * Retorna a música a ser tocada e incrementa a que está "tocando" para a próxima
 * @return o ponteiro da música a ser tocada, ou nullptr caso não tenha mais músicas
 */
node* Playlist::playNext() {
  if (playing->next != nullptr) {
    cout << "DEBUG: Entrei aqui";
    node* temp = playing;
    playing = playing->next;
    return temp;
  }
  cout << "DEBUG: Entrei no else"; 
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