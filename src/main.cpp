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

  size_t option = 12; // Opção selecionada no menu
  node* searchResult = nullptr; // Ponteiro para o nó retornado na busca
  size_t index = 0; // Indice na lista para as interações com o usuário
  size_t index2 = 0; // Indice na lista para as interações com o usuário
  // Variáveis temporárias para armazenar as entradas do usuário
  Playlist* tempPlaylist = nullptr;
  Song tempSong;
  string tempTitle = ""; 
  string tempArtist = "";

  // Variáveis para testar os métodos sobrecarregados
  LinkedList* list1 = new LinkedList;

  // Insere músicas previamente a uma lista
  tempSong.setTitle("Never Gonna Give You Up");
  tempSong.setArtist("Rick Astley");
  list1->insertEnd(tempSong);

  tempSong.setTitle("The Chain");
  tempSong.setArtist("Fleetwood Mac");
  list1->insertEnd(tempSong);

  // Cria uma segunda lista utilizando construtor cópia
  LinkedList* list2 = new LinkedList(*list1);

  // Adiciona mais músicas a segunda lista
  tempSong.setTitle("Cheia de Manias");
  tempSong.setArtist("Raça Negra");
  list2->insertEnd(tempSong);

  tempSong.setTitle("Evidências");
  tempSong.setArtist("Chitãozinho & Xororó");
  list2->insertEnd(tempSong);

  tempSong.setTitle("Sultans Of Swing");
  tempSong.setArtist("Dire Straits");
  list2->insertEnd(tempSong);

  // Remove da list2 as músicas da list1 por meio de sobrecarga
  list2->removePosition(*list1);

  // Insere as músicas dessa lista à lista global por meio de sobrecarga
  globalList->insertEnd(*list2);
 
  // Cria uma terceira lista a partir da concatenação das duas primeiras listas
  LinkedList* list3 = new LinkedList(*list1 + *list2);
  cout << "Músicas da lista 3:" << endl << endl;
  list3->display();

  // Executa o menu de funcionalidades enquanto a opção for diferente de 0
  while (option != 0) {
    // Limpa a tela e exibe as opções do menu
    // system ("clear");
    displayMenu();

    //Le a opção escolhida
    cin >> option;
    
    cout << endl << "----------------------------------------" << endl << endl;

    switch (option) {
      case 1 : { // Adicionar uma música
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
        globalList->insertEnd(tempSong);
        cout << "Música cadastrada com sucesso!" << endl;

        // Espera o usuário digitar enter para continuar
        cout << endl << "Pressione 'enter' para continuar." << endl;
        getchar();
        break;
      }
      case 2 : { // Remover uma música
        // Tratamento para garantir que há músicas adicionadas
        if (globalList->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
        } else {
          // Imprime a lista de músicas com seus indices
          globalList->display();

          // Lê a entrada
          cout << endl << "Insira o índice da música a ser removida (consulte a lista de músicas): ";
          cin >> index;

          // Tratamento para garantir que a entrada é válida
          while (index < 1 || index > globalList->getSize()) {
            cout << "Índice inválido! Tente novamente:" << endl;
            cin >> index;
          }

          // Acessa a música pelo indice
          searchResult = globalList->getNode(index);
          cout << "A música " << searchResult->data.getTitle()  << " - " << searchResult->data.getArtist() << " será removida do sistema." << endl;

          // Remove de todas as playlists
          if (playlists->getSize() > 0) {
            playlists->removeFromAll(searchResult->data);
          }

          // Remove da lista global
          globalList->removePosition(index);
        }
        
        // Espera o usuário digitar enter para continuar
        cout << endl << "Pressione 'enter' para continuar." << endl;
        getchar();
        getchar();
        break;
      }
      case 3 : { // Listar todas as músicas
        // Tratamento para garantir que há músicas adicionadas
        if (globalList->getSize() == 0) {
          cout << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
        } else {
          cout << "Músicas atuais do sistema:" << endl << endl;
          // Imprime a lista de músicas com seus indices
          globalList->display();
        }
      
        // Espera o usuário digitar enter para continuar
        cout << endl << "Pressione 'enter' para continuar." << endl;
        getchar();
        getchar();
        break;
      }
      case 4 : { // Buscar uma música 
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
        searchResult = globalList->search(tempSong);

        // Da o retorno
        if (searchResult == nullptr) {
          cout << endl << "Essa música ainda não existe no sistema. Por favor, verifique a ortografia e tente novamente ou adicione como nova música." << endl;
        } else {
          cout << endl << "A música " << searchResult->data.getTitle() << " - " << searchResult->data.getArtist() << " encontra-se no sistema!" << endl;
        }
        
        // Espera o usuário digitar enter para continuar
        cout << endl << "Pressione 'enter' para continuar." << endl;
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

        // Espera o usuário digitar enter para continuar
        cout << endl << "Pressione 'enter' para continuar." << endl;
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
          cout << endl << "Insira o índice da playlist a ser removida (consulte a lista de playlists): ";
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
        cout << endl << "Pressione 'enter' para continuar." << endl;
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
        cout << endl << "Pressione 'enter' para continuar." << endl;
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
          cout << "Playlist selecionada: " << tempPlaylist->getName() << endl;

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
            cout << endl << "A música não está cadastrada no sistema! Cadastre a música antes de adicionar a uma playlist." << endl;
          } else {
            // Adiciona na playlist
            tempPlaylist->insertSong(index, tempSong);
            cout << endl << "Música adicionada à playlist '" << tempPlaylist->getName() << "'" << endl;
          }
        }
        // Espera o usuário digitar enter para continuar 
        cout << endl << "Pressione 'enter' para continuar." << endl;
        getchar();
        getchar();
        break;
      }
      case 9 : { // Remover música de uma playlist
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
          cout << "Playlist selecionada: " << tempPlaylist->getName() << endl;

          // Tratamento para garantir que há músicas adicionadas
          if (tempPlaylist->getSongs()->getSize() == 0) {
            cout << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
          } else {
            // Imprime a lista de músicas com seus indices
            tempPlaylist->displayAllSongs(tempPlaylist->getSongs()->getHead());
            
            // Lê a entrada
            cout << "Insira o índice da música a ser removida (consulte a lista de músicas): ";
            cin >> index;

            // Tratamento para garantir que a entrada é válida
            while (index < 1 || index > tempPlaylist->getSongs()->getSize()) {
              cout << "Índice inválido! Tente novamente:" << endl;
              cin >> index;
            }
            
            // Remove a música
            tempPlaylist->removeSong(index);
            cout << endl << "Música removida da playlist '" << tempPlaylist->getName() << "'" << endl;
          }
        }
        
        // Espera o usuário digitar enter para continuar 
        cout << endl << "Pressione 'enter' para continuar." << endl;
        getchar();
        getchar();
        break;
      }
      case 10 : { // Mover música numa playlist
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
          cout << "Playlist selecionada: " << tempPlaylist->getName() << endl;

          // Tratamento para garantir que há músicas adicionadas
          if (tempPlaylist->getSongs()->getSize() == 0) {
            cout << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
          } else {
            // Imprime a lista de músicas com seus indices
            tempPlaylist->displayAllSongs(tempPlaylist->getSongs()->getHead());
            
            // Lê a entrada
            cout << endl << "Insira o índice da música a ser movida (consulte a lista de músicas): ";
            cin >> index;

            // Tratamento para garantir que a entrada é válida
            while (index < 1 || index > tempPlaylist->getSongs()->getSize()) {
              cout << "Índice inválido! Tente novamente:" << endl;
              cin >> index;
            }

            // Lê a entrada
            cout << "Insira o índice da posição para qual deseja movê-la (consulte a lista de músicas): ";
            cin >> index2;

            // Tratamento para garantir que a entrada é válida
            while (index2 < 1 || index2 > tempPlaylist->getSongs()->getSize()) {
              cout << "Índice inválido! Tente novamente:" << endl;
              cin >> index2;
            }
            
            // Move a música
            tempPlaylist->moveSong(index, index2);
            cout << endl << "Posição alterada com sucesso." << endl;
          }

        }

        // Espera o usuário digitar enter para continuar
        cout << endl << "Pressione 'enter' para continuar." << endl;
        getchar();
        getchar();
        break;
      }
      case 11 : { // Listar músicas de uma playlist
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
            cout << endl << "Ainda não há nada aqui. Experimente adicionar algumas músicas." << endl;
          } else {
            cout << "Músicas da playlist '" << tempPlaylist->getName() << "':" << endl;
            tempPlaylist->displayAllSongs(tempPlaylist->getSongs()->getHead());
          }
        }
        // Espera o usuário digitar enter para continuar
        cout << endl << "Pressione 'enter' para continuar." << endl;
        getchar();
        getchar();
        break;
      }
      default: {
        cout << "Encerrando o programa." << endl;
        break;
      }    
    }

  }

  // Libera a memória das listas globais
  delete globalList;
  delete playlists;

  delete list1;
  delete list2;
  delete list3;

  return 0;
}

/** Imprime as opções do menu de funcionalidades */
void displayMenu() {
  cout << "----------------------------------------" << endl;
  cout << "--------- BEM VINDO AO MUSIFY ----------" << endl;
  cout << "----- Seu gerenciador de playlists -----" << endl;
  cout << "----------------------------------------" << endl << endl;

  cout << "0 - Sair" << endl;
  cout << "----- Gerenciar músicas do sistema -----" << endl;
  cout << "1 - Adicionar uma música" << endl;
  cout << "2 - Remover uma música" << endl;
  cout << "3 - Listar todas as músicas" << endl;
  cout << "4 - Buscar uma música" << endl;

  cout << "---- Gerenciar playlists do sistema ----" << endl;
  cout << "5 - Adicionar uma playlist" << endl;
  cout << "6 - Remover uma playlist" << endl;
  cout << "7 - Listar todas as playlists" << endl;

  cout << "---- Gerenciar músicas numa playlist ---" << endl;
  cout << "8 - Adicionar música a uma playlist" << endl;
  cout << "9 - Remover música de uma playlist" << endl;
  cout << "10 - Mover música numa playlist" << endl;
  cout << "11 - Listar músicas de uma playlist" << endl << endl;

  cout << "----------------------------------------" << endl << endl;
  cout << "Escolha uma das opções acima: ";
}