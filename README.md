<p align="center">
  <a href="#sobre">Sobre</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#como-rodar">Como rodar?</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#funcionalidades-e-exemplos">Funcionalidades e exemplos</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#licença-e-autora">Licença e Autora</a>
</p>

## Sobre
Musify é uma implementação em C++ de um gerenciador de playlists desenvolvido para a disciplina de Linguagem de Programação I do curso Bacharelado em Tecnologia da Informação.

## Como rodar?


```bash
# Clone o projeto
$ git clone https://github.com/lorenatoscano/musify.git

# Compile o programa
$ make

# Execute no linux
$ ./musify 

# Ou execute no windows
$ .\musify.exe

```
## Funcionalidades e exemplos
### Gerenciar músicas do sistema
#### **Adicionar uma música**
Ação primordial de cadastrar músicas sistema. É necessário fazer isso antes de realizar qualquer outra ação com elas.

_Exemplos:_
```bash
Escolha uma das opções acima: 1

Título da música: Cheia de Manias
Artista da música: Raça Negra

Música cadastrada com sucesso!

## Escolha a opção 1 novamente para adicionar mais músicas

Título da música: Evidências
Artista da música: Chitãozinho & Xororó

Título da música: Sultans Of Swing
Artista da música: Dire Straits

Título da música: Runaway
Artista da música: Bon Jovi
```
#### **Remover uma música**
Esta opção remove a música do sistema e de todas as playlists que ela foi adicionada.

_Exemplos:_
```bash
Escolha uma das opções acima: 2

1 - Cheia de Manias - Raça Negra
2 - Evidências - Chitãozinho & Xororó
3 - Sultans Of Swing - Dire Straits
4 - Runaway - Bon Jovi

Insira o índice da música a ser removida (consulte a lista de músicas): 3

A música Sultans Of Swing - Dire Straits será removida do sistema.
```
#### **Listar todas as músicas**
Imprime a lista com os títulos e artistas de todas as músicas cadastradas no sistema.

_Exemplos:_
```bash
Escolha uma das opções acima: 3

Músicas atuais do sistema:

1 - Cheia de Manias - Raça Negra
2 - Evidências - Chitãozinho & Xororó
3 - Runaway - Bon Jovi
```
#### **Buscar uma música**
Verifica se uma música está cadastrada no sistema. Não é case sensitive, ou seja, não diferencia maiúsculas e minúsculas.

_Exemplos:_
```bash
Escolha uma das opções acima: 4

Título da música: cheia de manias
Artista da música: rAçA NegRa

A música Cheia de Manias - Raça Negra encontra-se no sistema!

## Escolha a opção 4 novamente para buscar outra música

Título da música: Basta Você me Ligar
Artista da música: Os Barões da Pisadinha

Essa música ainda não existe no sistema. Por favor, verifique a ortografia e tente novamente ou adicione como nova música.
```
### Gerenciar playlists do sistema
#### **Adicionar uma playlist**
Uma playlist é representada por seu nome.

_Exemplos:_
```bash
Escolha uma das opções acima: 5

Nome da playlist: Webchurrasco

Playlist criada! Adicione algumas músicas.

## Escolha a opção 4 novamente para adicionar outra playlist

Nome da playlist: Favoritas de Rock

Playlist criada! Adicione algumas músicas.

## Escolha a opção 4 novamente para adicionar outra playlist

Nome da playlist: Para treinar

Playlist criada! Adicione algumas músicas.
```
#### **Remover uma playlist**
_Exemplos:_
```bash
Escolha uma das opções acima: 6

1 - Webchurrasco
2 - Favoritas de Rock
3 - Para treinar

Insira o índice da playlist a ser removida (consulte a lista de playlists): 3

Remoção concluída com sucesso.
```
#### **Listar todas as playlists**
Imprime a lista com os nomes das playlists cadastradas no sistema.

_Exemplos:_
```bash
Escolha uma das opções acima: 7

Playlists atuais do sistema:

1 - Webchurrasco
2 - Favoritas de Rock
```
### Gerenciar músicas numa playlist
#### **Adicionar música a uma playlist**
É necessário que a música esteja cadastrada no sistema antes de tentar adicioná-la a uma playlist.

_Exemplos:_
```bash
Escolha uma das opções acima: 8

Insira o índice da playlist desejada (consulte a lista de playlists): 1

Playlist selecionada: Webchurrasco

Título da música: Cheia de Manias
Artista da música: Raça Negra

Em qual posição deseja adicionar (consulte a lista de músicas): 1

Música adicionada à playlist 'Webchurrasco'

## Escolha a opção 8 novamente para adicionar outra música

Insira o índice da playlist desejada (consulte a lista de playlists): 1

Playlist selecionada: Webchurrasco

Título da música: Evidências
Artista da música: Chitãozinho & Xororó

Em qual posição deseja adicionar (consulte a lista de músicas): 1 

Música adicionada à playlist 'Webchurrasco'

## Escolha a opção 8 novamente para adicionar outra música

Insira o índice da playlist desejada (consulte a lista de playlists): 2

Playlist selecionada: Favoritas de Rock

Título da música: Runaway
Artista da música: Bon Jovi

Em qual posição deseja adicionar (consulte a lista de músicas): 1

Música adicionada à playlist 'Favoritas de Rock'
```
#### **Remover música de uma playlist**
_Exemplos:_
```bash
Escolha uma das opções acima: 9

Insira o índice da playlist desejada (consulte a lista de playlists): 2

Playlist selecionada: Favoritas de Rock
1 - Runaway - Bon Jovi

Insira o índice da música a ser removida (consulte a lista de músicas): 1

Música removida da playlist 'Favoritas de Rock'
```
#### **Mover música numa playlist**
Muda a posição de uma música dentro da playlist.

_Exemplos:_
```bash
Escolha uma das opções acima: 10

Insira o índice da playlist desejada (consulte a lista de playlists): 1

Playlist selecionada: Webchurrasco

1 - Evidências - Chitãozinho & Xororó
2 - Cheia de Manias - Raça Negra

Insira o índice da música a ser movida (consulte a lista de músicas): 1
Insira o índice da posição para qual deseja movê-la (consulte a lista de músicas): 2

Posição alterada com sucesso.
```
#### **Listar músicas de uma playlist**
Imprime a lista com os títulos e artistas de todas as músicas de uma playlist.

_Exemplos:_
```bash
Escolha uma das opções acima: 11

Insira o índice da playlist desejada (consulte a lista de playlists): 1

Músicas da playlist 'Webchurrasco':
1 - Cheia de Manias - Raça Negra
2 - Evidências - Chitãozinho & Xororó
```
## Limitações
- O sistema suporta somente músicas de um único artista. Caso a música tenha mais de um, é necessário cadastrar somente o principal.
## Licença e Autora
Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](https://github.com/lorenatoscano/musify/blob/main/LICENSE) para mais detalhes.

Feito por [Luiza Lorena Toscano de Medeiros](https://github.com/lorenatoscano).
