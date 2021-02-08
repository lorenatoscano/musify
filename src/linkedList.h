#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "song.h"

/** Classe que representa uma lista ligada */
class LinkedList {
  private:
    /** Struct que representa um nó da lista ligada e armazena objetos do tipo música */
    struct node {
      Song data; /**< Armazena um objeto do tipo música */ 
      node* next; /**< Ponteiro para o próximo nó */ 
    };
    node* head; /**< Ponteiro para o primeiro nó */ 
    node* tail; /**< Ponteiro para o último nó */
  public:
    LinkedList(); /**< Construtor da lista ligada */
    ~LinkedList(); /**< Destrutor da lista ligada */

    void createNode(Song value); /**< Cria um novo nó */
    void display(); /**< Exibe o conteúdo dos nós da lista */
};





#endif