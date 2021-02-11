# "make" chama os alvos makeobjects e main
all: makeobjects musify

# Cria a pasta "objects"
makeobjects:
		mkdir -p objects

# Compila tudo e cria o executável "musify"
musify: objects/main.o objects/utils.o objects/song.o objects/linkedList.o
		g++ objects/*.o -Iinclude -Wall -pedantic -o musify

objects/main.o: src/main.cpp objects/utils.o objects/song.o objects/linkedList.o
		g++ src/main.cpp -Iinclude -c -o objects/main.o

objects/utils.o: src/utils.cpp
		g++ src/utils.cpp -Iinclude -c -o objects/utils.o

objects/song.o: src/song.cpp
		g++ src/song.cpp -Iinclude -c -o objects/song.o

objects/linkedList.o: src/linkedList.cpp objects/utils.o objects/song.o
		g++ src/linkedList.cpp -Iinclude -c -o objects/linkedList.o

# Remove a pasta objects e o arquivo executável
clean:
		rm -rf objects
		rm musify