#include <iostream>
#include <cstdlib>
#include <string>

#include "song.h"
#include "linkedList.h"
#include "utils.h"
#include "playlist.h"
#include "listOfPlaylists.h"

using namespace std;

void displayMenu();

int main(int argc, char const *argv[])
{ 
  // Cria a lista global de músicas do sistema
  LinkedList* globalList = new LinkedList;
  // Cria a lista de armazenar as playlists do sistema
  ListOfPlaylists* playlists = new ListOfPlaylists;


  size_t option = 11; // Opção selecionada no menu
  Song tempSong; // Música e atributos temporários para as interações com o usuário
  string tempTitle = ""; 
  string tempArtist = "";
  node* searchResult = nullptr; // Ponteiro para o nó retornado na busca
  Playlist* tempPlaylist = nullptr;
  size_t index = 0; // Indice na lista para as interações com o usuário

  // Variaveis e valores estabelecidos para testar as funcionalidades
  Playlist* p1 = nullptr;
  p1 = new Playlist;

  Song* s1 = new Song;
  Song* s2 = new Song;
  Song* s3 = new Song;

  s1->setTitle("New Rules");
  s1->setArtist("Dua Lipa");

  s2->setTitle("Paradise");
  s2->setArtist("Coldplay");

  s3->setTitle("Zombie");
  s3->setArtist("The Cramberries");
  
  globalList->insertPosition(2, *s1);
  globalList->insertPosition(1, *s2);
  globalList->insertPosition(2, *s3);

  p1->setName("Favoritas");
  p1->insertSong(2, *s1);
  p1->insertSong(1, *s2);
  p1->insertSong(2, *s3);

  cout << p1->getName() << ":" <<  endl;
  p1->displayAllSongs(p1->getSongs()->getHead());

  node* temp = p1->playNext();
  if (temp != nullptr) {
    cout << "Tocando " << temp->data.getTitle() << " - " << temp->data.getArtist() << endl;
  } else {
    cout << "Fim da playlist" << endl;
  }
 

  // Executa o menu de funcionalidades enquanto a opção for diferente de 0
  while (option != 0) {
    // Limpa a tela e exibe as opções do menu
    system ("CLS");
    displayMenu();

    //Le a opção escolhida
    cin >> option;
    
    cout << endl << "----------------------------------------" << endl << endl;

    switch (option) {
      case 1 : { // Buscar uma música 
        // Le as entradas
        cout << "Título da música: ";
        cin.ignore(256, '\n');
        getline(cin, tempTitle);
        cout << "Artista da música: ";
        getline(cin, tempArtist);

        // Atribui num objeto do tipo Song
        tempSong.setTitle(tempTitle);
        tempSong.setArtist(tempArtist);
        
        // Efetua a busca
        cout << "Buscando..." << endl;
        searchResult = globalList->search(tempSong);

        // Da o retorno
        if (searchResult == nullptr) {
          cout << "Essa música ainda não existe no sistema. Por favor, verifique a ortografia e tente novamente ou adicione como nova música." << endl;
        } else {
          cout << "A música " << searchResult->data.getTitle() << " - " << searchResult->data.getArtist() << " encontra-se no sistema!" << endl;
        }
        
        // Espera o usuário digitar enter para continuar
        getchar();
        break;
      }
      case 2 : { // Adicionar uma música
        // Le as entradas
        cout << "Título da música: ";
        cin.ignore(256, '\n');
        getline(cin, tempTitle);
        cout << "Artista da música: ";
        getline(cin, tempArtist);

        // Atribui num objeto do tipo Song
        tempSong.setTitle(tempTitle);
        tempSong.setArtist(tempArtist);

        // Adiciona ao final da lista global
        cout << "Adicionando..." << endl;
        globalList->insertEnd(tempSong);

        // Espera o usuário digitar enter para continuar
        getchar();
        break;
      }
      case 3 : { // Remover uma música
        // Tratamento para garantir que há músicas adicionadas
        if (globalList->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
        } else {
          // Imprime a lista de músicas com seus indices
          globalList->display();

          // Lê a entrada
          cout << "Insira o índice da música a ser removida (consulte a lista de músicas): ";
          cin >> index;

          // Tratamento para garantir que a entrada é válida
          while (index < 1 || index > globalList->getSize()) {
            cout << "Índice inválido! Tente novamente:" << endl;
            cin >> index;
          }

          // Acessa a música pelo indice
          searchResult = globalList->getNode(index);
          cout << "A música " << searchResult->data.getTitle()  << " - " << searchResult->data.getArtist() << " será removida do sistema." << endl;

          // Remove da lista global
          globalList->removePosition(index);

          // Remove de todas as playlists
          playlists->removeFromAll(searchResult->data);
        }
        
        // Espera o usuário digitar enter para continuar
        getchar();
        getchar();
        break;
      }
      case 4 : { // Listar todas as músicas
        // Tratamento para garantir que há músicas adicionadas
        if (globalList->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
        } else {
          cout << "Músicas atuais do sistema:" << endl << endl;
          // Imprime a lista de músicas com seus indices
          globalList->display();
        }
      
        // Espera o usuário digitar enter para continuar
        getchar();
        getchar();
        break;
      }
      case 5 : { // Adicionar uma playlist
        // Le a entrada
        cout << "Nome da playlist: ";
        cin.ignore(256, '\n');
        getline(cin, tempTitle);

        // Aloca a nova playlist
        tempPlaylist = new Playlist;

        // Adiciona o nome escolhido
        tempPlaylist->setName(tempTitle);

        // Insere na lista
        playlists->insertPlaylist(tempPlaylist);

        cout << "Playlist criada! Adicione algumas músicas." << endl;
        // Espera o usuário digitar enter para continuar
        getchar();
        break;
      }
      case 6 : { // Remover uma playlist
        // Tratamento para garantir que há playlists adicionadas
        if (playlists->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas playlists." << endl;
        } else {
          // Imprime a lista de playlists com seus indices
          playlists->display();

          // Lê a entrada
          cout << "Insira o índice da playlist a ser removida (consulte a lista de playlists): ";
          cin >> index;

          // Tratamento para garantir que a entrada é válida
          while (index < 1 || index > playlists->getSize()) {
            cout << "Índice inválido! Tente novamente:" << endl;
            cin >> index;
          }
          
          // Remove a playlist
          playlists->removePlaylist(index);
          cout << "Remoção concluída com sucesso." << endl;
        }

        // Espera o usuário digitar enter para continuar
        getchar();
        getchar();
        break;
      }
      case 7 : { // Listar todas as playlists
        // Tratamento para garantir que há playlists adicionadas
        if (playlists->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas playlists." << endl;
        } else {
          cout << "Playlists atuais do sistema:" << endl << endl;
          // Imprime a lista de músicas com seus indices
         playlists->display();
        }
        // Espera o usuário digitar enter para continuar
        getchar();
        getchar();
        break;
      }
      case 8 : { // Adicionar música a uma playlist
        // Tratamento para garantir que há playlists adicionadas
        if (playlists->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas playlists." << endl;
        } else {
          // Lê a entrada
          cout << "Insira o índice da playlist desejada (consulte a lista de playlists): ";
          cin >> index;

          // Tratamento para garantir que a entrada é válida
          while (index < 1 || index > playlists->getSize()) {
            cout << "Índice inválido! Tente novamente:" << endl;
            cin >> index;
          }

          // Obtém a playlist pelo índice
          tempPlaylist = playlists->getPlaylist(index);

          // Le as entradas
          cout << "Título da música: ";
          cin.ignore(256, '\n');
          getline(cin, tempTitle);
          cout << "Artista da música: ";
          getline(cin, tempArtist);
          cout << "Em qual posição deseja adicionar (consulte a lista de músicas): ";
          cin >> index;

          // Tratamento para garantir que a posição é válida
          while (index < 1) {
            cout << "Posição inválida. Tente novamente:" << endl;
            cin >> index;
          }
            // Atribui num objeto do tipo Song
            tempSong.setTitle(tempTitle);
            tempSong.setArtist(tempArtist);
            
            // Busca pela música no sistema
            searchResult = globalList->search(tempSong);
            if (searchResult == nullptr) {
              cout << "A música não está cadastrada no sistema! Cadastre a música antes de adicionar a uma playlist." << endl;
            } else {
              // Adiciona na playlist
              tempPlaylist->insertSong(index, tempSong);
            }
        }
        // Espera o usuário digitar enter para continuar 
        getchar();
        getchar();
        break;
      }
      case 9 : { // Remover música de uma playlist

        break;
      }
      case 10 : { // Listar músicas de uma playlist
        // Tratamento para garantir que há playlists adicionadas
        if (playlists->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas playlists." << endl;
        } else {
          // Lê a entrada
          cout << "Insira o índice da playlist desejada (consulte a lista de playlists): ";
          cin >> index;

          // Tratamento para garantir que a entrada é válida
          while (index < 1 || index > playlists->getSize()) {
            cout << "Índice inválido! Tente novamente:" << endl;
            cin >> index;
          }

          // Obtém a playlist pelo índice
          tempPlaylist = playlists->getPlaylist(index);

          // Tratamento para garantir que há músicas adicionadas
          if (tempPlaylist->getSongs()->getSize() == 0) {
            cout << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
          } else {
            cout << "Músicas da playlist '" << tempPlaylist->getName() << "':" << endl;
            tempPlaylist->displayAllSongs(tempPlaylist->getSongs()->getHead());
          }
        }
        // Espera o usuário digitar enter para continuar
        getchar();
        getchar();
        break;
      }
      
      default:
        break;
    }

  }
  

  

  // queue->display();

  // node* result = queue->getNode(2);
  // cout << result << " - ";
  // cout << result->data.getTitle() << endl;

  // queue->removePosition(2);

  // cout << endl;
  // queue->display();

  // Song tempSong;
  // tempSong.setArtist("Dua Lipa");
  // tempSong.setTitle("NeW Rules");
  // node* result = queue->search(tempSong);
  // cout << result << endl;

  delete s1;
  delete s2;
  delete s3;

  delete p1;

  delete tempPlaylist;
  delete globalList;
  delete playlists;

  return 0;
}

void displayMenu() {
  cout << "----------------------------------------" << endl;
  cout << "--------- BEM VINDO AO MUSIFY ----------" << endl;
  cout << "----- Seu gerenciador de playlists -----" << endl;
  cout << "----------------------------------------" << endl << endl;

  cout << "0 - Sair" << endl;
  cout << "----- Gerenciar músicas do sistema -----" << endl;
  cout << "1 - Buscar uma música" << endl;
  cout << "2 - Adicionar uma música" << endl;
  cout << "3 - Remover uma música" << endl;
  cout << "4 - Listar todas as músicas" << endl;

  cout << "---- Gerenciar playlists do sistema ----" << endl;
  cout << "5 - Adicionar uma playlist" << endl;
  cout << "6 - Remover uma playlist" << endl;
  cout << "7 - Listar todas as playlists" << endl;

  cout << "---- Gerenciar músicas numa playlist ---" << endl;
  cout << "8 - Adicionar música a uma playlist" << endl;
  cout << "9 - Remover música de uma playlist" << endl << endl;
  cout << "10 - Listar músicas de uma playlist" << endl;

  cout << "----------------------------------------" << endl << endl;
  cout << "Escolha uma das opções cima: ";
}