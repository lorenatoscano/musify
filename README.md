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

# Entre na pasta
$ cd musify

# Compile o programa
$ make

# Execute
$ ./musify 

```
## Funcionalidades e exemplos
Para esses exemplos, note que já existem algumas músicas e playlists previamente cadastradas ao sistema. Veja a seção de [Funções e operadores sobrecarregados](#funções-e-operadores-sobrecarregados) para mais detalhes.
### Gerenciar músicas do sistema
#### **Adicionar uma música**
Ação primordial de cadastrar músicas sistema. É necessário fazer isso antes de realizar qualquer outra ação com elas.

_Exemplos:_
```bash
Escolha uma das opções acima: 1

Título da música: Runaway
Artista da música: Bon Jovi

Música cadastrada com sucesso!

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

### Funções e operadores sobrecarregados
Os casos de teste estão implementados no início do main. Ao rodar o programa, antes de acessar o menu do gerenciador, será impresso o conteúdo das listas e playlists "teste" e suas mudanças ao longo de cada etapa.

#### **Construtor cópia**
Recebe uma referência de uma lista e copia todos os seus elementos para a lista atual.

`Uso da função: linha 54 do main.cpp`

Cria a lista 2 a partir da cópia da lista 1.
#### **Sobrecarga de remover elementos**
Recebe uma lista ligada como parâmetro e remove todos os seus elementos da lista atual.

`Uso da função: linha 74 do main.cpp`

Remove da lista 2 as músicas que estão na lista 1.
#### **Sobrecarga de adicionar elementos**
Recebe uma lista ligada como parâmetro e adiciona todos os seus elementos na lista atual.

`Uso da função: linha 80 do main.cpp`

Aqui utilizo a sobrecarga para inserir previamente as músicas de teste da lista 2 na lista global. Isso pode ser verificado escolhendo a opção 3 do menu, que lista todas as músicas da lista global do sistema.

#### **Sobrecarga de operador + para concatenação**
Concatena a lista atual com a lista passada por referência e retorna uma lista final.

`Uso da função: linha 84 do main.cpp`

Cria a lista 3 a partir da concatenação lista 1 + lista 2.
#### **Sobrecarga de operador de extração >>**
Extrai o último elemento da lista atribuindo seus valores ao nó recebido como argumento.

`Uso da função: linha 92 do main.cpp`

Extrai o último nó da lista 3.

#### **Sobrecarga de operador de inserção <<**
Insere o nó passado por argumento ao final da lista atual.

`Uso da função: linha 101 do main.cpp`

Adiciona novamente o nó ao fim da lista 3.

#### **Sobrecarga de adicionar músicas**
Recebe uma referência de uma playlist e copia todas as suas músicas para a playlist atual.

`Uso da função: linha 132 do main.cpp`

Utilizo para inserir as músicas da playlist 1 na playlist 2.

#### **Sobrecarga de remover músicas**
Recebe uma referência de uma playlist e remove todas as suas músicas da playlist atual. Retorna a quantidade de músicas removidas.

`Uso da função: linha 138 do main.cpp`

Remove da playlist 2 as músicas que estão na playlist 1.

#### **Construtor cópia de playlist**
Recebe uma referência de uma playlist e copia todas as suas músicas para a playlist atual.

`Uso da função: linha 144 do main.cpp`

Cria uma playlist 3 a partir da cópia da playlist 1.

#### **Sobrecarga de operador + para união**
Retorna uma nova playlist a partir da união da playlist atual com a passada por referência.

`Uso da função: linha 159 do main.cpp`

Cria a playlist 4 a partir da união entre as playlists 1 e 3.

#### **Sobrecarga de operador + para adicionar música**
Retorna uma nova playlist a partir da cópia da playlist atual, incluindo a nova música passada por argumento.

`Uso da função: linha 168 do main.cpp`

Cria a playlist 5 a partir da cópia da playlist 4 e a música "Panic - The Smiths".

#### **Sobrecarga de operador - para diferença**
Faz a diferença entre duas playlists, ou seja, retorna uma playlist final contendo todas as músicas da playlist atual que não estão na playlist passada por referência.

`Uso da função: linha 175 do main.cpp`

Cria a playlist 6 a partir da diferença entre as playlists 5 e 3.

#### **Sobrecarga de operador - para remover música**
Retorna uma nova playlist a partir da cópia da playlist atual, removendo a música passada por argumento.

`Uso da função: linha 182 do main.cpp`

Cria a playlist 7 a partir da cópia da playlist 6 menos a música "Panic - The Smiths".

#### **Sobrecarga de operador de extração >>**
Extrai a última música da playlist atribuindo seus valores a música recebida como argumento.

`Uso da função: linha 190 do main.cpp`

Extrai a última música da playlist 5.

#### **Sobrecarga de operador de inserção <<**
Insere a música recebida ao final da playlist atual.

`Uso da função: linha 199 do main.cpp`

Insere novamente a música "Panic - The Smiths" na playlist 5.

## Limitações
- O sistema suporta somente músicas de um único artista. Caso a música tenha mais de um, é necessário cadastrar somente o principal.
## Licença e Autora
Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](https://github.com/lorenatoscano/musify/blob/main/LICENSE) para mais detalhes.

Feito por [Luiza Lorena Toscano de Medeiros](https://github.com/lorenatoscano).
