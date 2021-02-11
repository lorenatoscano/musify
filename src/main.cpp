#include <iostream>
#include <cstdlib>
#include <locale>

#include "song.h"
#include "linkedList.h"
#include "utils.h"

using namespace std;

void displayMenu();

int main(int argc, char const *argv[])
{
  LinkedList* queue = new LinkedList;

  size_t option = 11;

  while (option != 0) {
    system ("CLS");
    displayMenu();
    cin >> option;
  }
  

  // Song* s1 = new Song;
  // Song* s2 = new Song;
  // Song* s3 = new Song;

  

  // s1->setTitle("New Rules");
  // s1->setArtist("Dua Lipa");

  // s2->setTitle("Paradise");
  // s2->setArtist("Coldplay");

  // s3->setTitle("Zombie");
  // s3->setArtist("The Cramberries");
  
  // queue->insertPosition(2, *s1);
  // queue->insertPosition(1, *s2);
  // queue->insertPosition(2, *s3);

  // queue->display();

  // node* result = queue->getNode(2);
  // cout << result << " - ";
  // cout << result->data.getTitle() << endl;

  // queue->removePosition(2);

  // cout << endl;
  // queue->display();

  // Song searchSong;
  // searchSong.setArtist("Dua Lipa");
  // searchSong.setTitle("NeW Rules");
  // node* result = queue->search(searchSong);
  // cout << result << endl;

  // delete s1;
  // delete s2;
  // delete s3;

  delete queue;

  return 0;
}

void displayMenu() {
  cout << "----------------------------------------" << endl;
  cout << "--------- BEM VINDO AO MUSIFY ----------" << endl;
  cout << "----- Seu gerenciador de playlists -----" << endl;
  cout << "----------------------------------------" << endl << endl;

  cout << "Escolha uma das opções abaixo:" << endl << endl;

  cout << "0 - Sair" << endl;
  cout << "----- Gerenciar músicas do sistema -----" << endl;
  cout << "1 - Buscar uma música" << endl;
  cout << "2 - Adicionar uma música" << endl;
  cout << "3 - Remover uma música" << endl;
  cout << "4 - Listas todas as músicas" << endl;

  cout << "---- Gerenciar playlists do sistema ----" << endl;
  cout << "5 - Adicionar uma playlist" << endl;
  cout << "6 - Remover uma playlist" << endl;
  cout << "7 - Listas todas as playlists" << endl;

  cout << "---- Gerenciar músicas numa playlist ---" << endl;
  cout << "8 - Listar músicas de uma playlist" << endl;
  cout << "9 - Adicionar música a uma playlist" << endl;
  cout << "10 - Remover música de uma playlist" << endl << endl;

  cout << "----------------------------------------" << endl << endl;
}