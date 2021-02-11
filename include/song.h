#ifndef SONG_H
#define SONG_H

#include <iostream>

 
/** Classe que representa uma música do sistema */
class Song {
  private:
    std::string title;  /**< Título da música */ 
    std::string artist; /**< Artista da música */ 
  public:
    Song(); /**< Construtor da música */
    ~Song(); /**< Destrutor da música */       

    std::string getTitle(); /**< Obtém o título da música */
    void setTitle(std::string _title); /**< Adiciona o título da música */

    std::string getArtist(); /**< Obtém o artista da música */
    void setArtist(std::string _artist); /**< Adiciona o artista da música */
};


#endif