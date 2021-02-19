# "make" chama os alvos makeobjects e main
all: makeobjects musify

# Cria a pasta "objects"
makeobjects:
		mkdir -p objects

# Compila tudo e cria o executável "musify"
musify: objects/main.o objects/utils.o objects/song.o objects/linkedList.o objects/playlist.o objects/listOfPlaylists.o
		g++ objects/*.o -Iinclude -Wall -pedantic -ansi -std=c++11 -g -o musify

objects/main.o: src/main.cpp objects/utils.o objects/song.o objects/linkedList.o
		g++ src/main.cpp -Iinclude -Wall -pedantic -ansi -std=c++11 -g -c -o objects/main.o

objects/utils.o: src/utils.cpp
		g++ src/utils.cpp -Iinclude -Wall -pedantic -ansi -std=c++11 -g -c -o objects/utils.o

objects/song.o: src/song.cpp
		g++ src/song.cpp -Iinclude -Wall -pedantic -ansi -std=c++11 -g -c -o objects/song.o

objects/linkedList.o: src/linkedList.cpp objects/utils.o objects/song.o
		g++ src/linkedList.cpp -Iinclude -Wall -pedantic -ansi -std=c++11 -g -c -o objects/linkedList.o

objects/playlist.o: src/playlist.cpp objects/linkedList.o objects/song.o
		g++ src/playlist.cpp -Iinclude -Wall -pedantic -ansi -std=c++11 -g -c -o objects/playlist.o

objects/listOfPlaylists.o: src/listOfPlaylists.cpp objects//playlist.o
		g++ src/listOfPlaylists.cpp -Iinclude -Wall -pedantic -ansi -std=c++11 -g -c -o objects/listOfPlaylists.o

# Remove a pasta objects e o arquivo executável
clean:
		rm -rf objects
		rm musify