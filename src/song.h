#ifndef SONG_H
#define SONG_H

#include <iostream>

using namespace std;
 
/** Classe que representa uma música do sistema */
class Song {
  private:
    string title;  /**< Título da música */ 
    string artist; /**< Artista da música */ 
  public:
    Song(); /**< Construtor da música */
    ~Song(); /**< Destrutor da música */       

    string getTitle(); /**< Obtém o título da música */
    void setTitle(string _title); /**< Adiciona o título da música */

    string getArtist(); /**< Obtém o artista da música */
    void setArtist(string _artist); /**< Adiciona o artista da música */
};


#endif