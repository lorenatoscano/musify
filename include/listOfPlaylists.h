#ifndef LISTOFPLAYLISTS_H
#define LISTOFPLAYLISTS_H

#include <iostream>
#include "playlist.h"

/** Struct que representa um nó da lista ligada e armazena objetos do tipo ponteiro de playlist */
struct node_ {
  Playlist* data;
  node_* next;
};

/** Classe que representa uma lista ligada de playlists */
class ListOfPlaylists {
  private:
    node_* head; /**< Ponteiro para o primeiro nó */ 
    node_* tail; /**< Ponteiro para o último nó */
    size_t size; /**< Tamanho da lista */
  public:
    ListOfPlaylists(); /**< Construtor da lista ligada */
    ~ListOfPlaylists(); /**< Destrutor da lista ligada */

    size_t getSize(); /**< Obtém o tamanho da lista */

    void insertPlaylist(Playlist* value); /**< Insere um nó da playlist no fim da lista */

    void removePlaylist(size_t pos); /**< Remove o nó da playlist de uma posição específica */

    void display(); /**< Exibe o conteúdo dos nós da lista */

};


#endif