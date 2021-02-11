# "make" chama os alvos makeobjects e main
all: makeobjects musify

# Cria a pasta "objects"
makeobjects:
		mkdir -p objects

# Compila tudo e cria o executável "musify"
musify: main utils song linkedList
		g++ objects/*.o -Iinclude -Wall -pedantic -o musify

main: src/main.cpp utils song linkedList
		g++ src/main.cpp -Iinclude -c -o objects/main.o

utils: src/utils.cpp
		g++ src/utils.cpp -Iinclude -c -o objects/utils.o

song: src/song.cpp
		g++ src/song.cpp -Iinclude -c -o objects/song.o

linkedList: src/linkedList.cpp utils song
		g++ src/linkedList.cpp -Iinclude -c -o objects/linkedList.o

# Remove a pasta objects e o arquivo executável
clean:
		rm -rf objects
		rm musify