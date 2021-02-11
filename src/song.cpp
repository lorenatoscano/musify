#include "song.h"

using namespace std;

Song::Song() {
}

Song::~Song() {
}

// Getters dos atributos de Song

string Song::getTitle() {
  return title;
}

string Song::getArtist() {
  return artist;
}


// Setters dos atributos de Song

void Song::setTitle(string _title) {
  title = _title;
}

void Song::setArtist(string _artist) {
  artist = _artist;
}
