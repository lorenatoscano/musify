#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "linkedList.h"
#include "song.h"

/** Classe que representa uma playlist */
class Playlist {
  private:
    std::string name; /**< Nome da playlist */
    LinkedList* songs; /**< Ponteiro para a lista que armazena as músicas */
    node* playing; /**< Ponteiro para o nó da música que está "tocando" */
    size_t count; /**< Contador para o método de display */
  public:
    Playlist(); /**< Construtor da playlist */
    ~Playlist(); /**< Destrutor da playlist */

    Playlist(const Playlist& old); /**< Construtor cópia da playlist */

    LinkedList* getSongs(); /**< Obtém o ponteiro da lista de músicas */

    std::string getName(); /**< Obtém o nome da playlist */
    void setName(std::string _name); /**< Adiciona o nome da playlist */

    void insertSong(size_t pos, Song value); /**< Insere uma música na playlist */
    void removeSong(size_t pos); /**< Remove uma música da playlist */
    void moveSong(size_t start, size_t end); /**< Move a música para outra posição na playlist */

    void insertSong(Playlist& toInsert); /**< Versão sobrecarregada do método de inserção */
    size_t removeSong(Playlist& toRemove); /**< Versão sobrecarregada do método de remoção */

    node* playNext(); /**< Retorna a próxima música a ser tocada */

    void displayAllSongs(node* current); /**< Imprime todas as músicas que compoem uma playlist */
};

#endif