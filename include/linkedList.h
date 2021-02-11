#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "song.h"

/** Struct que representa um nó da lista ligada e armazena objetos do tipo música */
struct node {
  Song data; /**< Armazena um objeto do tipo música */ 
  node* next; /**< Ponteiro para o próximo nó */ 
};

/** Classe que representa uma lista ligada */
class LinkedList {
  private:
    node* head; /**< Ponteiro para o primeiro nó */ 
    node* tail; /**< Ponteiro para o último nó */
    size_t size; /**< Tamanho da lista */
  public:
    LinkedList(); /**< Construtor da lista ligada */
    ~LinkedList(); /**< Destrutor da lista ligada */

    void insertStart(Song value); /**< Insere um nó no início */
    void insertEnd(Song value); /**< Insere um nó no fim */
    void insertPosition(size_t pos, Song value); /**< Insere um nó numa posição específica */
    
    void removeFirst(); /**< Remove o primeiro nó */
    void removeLast(); /**< Remove o último nó */
    void removePosition(size_t pos); /**< Remove o nó de uma posição específica */

    node* search(Song searchSong); /**< Busca um nó com base nos atributos da música */
    node* getNode(size_t pos); /**< Retorna um nó com base na posição */

    void display(); /**< Exibe o conteúdo dos nós da lista */
};


#endif