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

    LinkedList(const LinkedList& oldList); /**< Construtor cópia da lista ligada */

    LinkedList operator+ (const LinkedList& secondList); /**< Concatenação de listas */

    void operator>> (node*& lastNode); /**< Extrai o último elemento da lista */
    void operator<< (node*& newNode); /**< Insere um nó no fim da lista */

    node* getHead(); /**< Obtém o ponteiro do head */
    node* getTail(); /**< Obtém o ponteiro do tail */
    size_t getSize(); /**< Obtém o tamanho da lista */

    void insertStart(Song value); /**< Insere um nó no início */
    void insertEnd(Song value); /**< Insere um nó no fim */
    void insertPosition(size_t pos, Song value); /**< Insere um nó numa posição específica */
    
    void insertEnd(LinkedList& toInsert); /**< Versão sobrecarregada do método de inserção */

    void removeFirst(); /**< Remove o primeiro nó */
    void removeLast(); /**< Remove o último nó */
    void removePosition(size_t pos); /**< Remove o nó de uma posição específica */

    void removePosition(LinkedList& toRemove); /**< Versão sobrecarregada do método de remoção */

    node* search(Song searchSong); /**< Busca um nó com base nos atributos da música */
    node* getNode(size_t pos); /**< Retorna um nó com base na posição */
    size_t getPosition(Song searchSong); /**< Retorna a posição de uma música na lista */

    void display(); /**< Exibe o conteúdo dos nós da lista */
};


#endif