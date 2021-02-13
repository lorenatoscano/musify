#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "linkedList.h"
#include "song.h"
#include "utils.h"

/** Classe que representa uma playlist */
class Playlist {
  private:
    std::string name; /**< Nome da playlist */
    LinkedList songs; /**< Lista que armazena as músicas */
  public:
    Playlist(); /**< Construtor da playlist */
    ~Playlist(); /**< Destrutor da playlist */

    std::string getName(); /**< Obtém o nome da playlist */
    void setName(std::string _name); /**< Adiciona o nome da playlist */

    void insertSong(Song value); /**< Insere uma música na playlist */
    void removeSong(); /**< Remove uma música da playlist */
    
    node* playNext(node* current); /**< Retorna a próxima música a ser tocada */

    void displayAllSongs(node* current); /**< Imprime todas as músicas que compoem uma playlist */
};

#endif