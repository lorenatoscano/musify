#include "playlist.h"

using namespace std;

Playlist::Playlist() {
}

Playlist::~Playlist() {
}

string Playlist::getName() {
  return name;
}

void Playlist::setName(string _name) {
  name = _name;
}

/**
 * Função recursiva que imprime todas as músicas que formam a playlist
 * @param current ponteiro para o nó atual contendo a música a ser impressa
 */
void Playlist::displayAllSongs(node* current) {
  // Condição de parada
  if (current == nullptr) {
    return;
  }
  // Imprime a música atual
  cout << current->data.getTitle() << " - " << current->data.getArtist() << endl;

  // Chamada recursiva
  displayAllSongs(current->next);
}