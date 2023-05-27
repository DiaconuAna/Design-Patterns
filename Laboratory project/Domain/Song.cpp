//
// Created by amina on 3/8/2023.
//

#include "Song.h"

Song::Song():_title{""}, _genre{""}, _artist{""}, _release_year{0} {

}

Song::Song(const std::string &title, const std::string &genre, int year, const std::string& artist): _title{title}, _genre{genre}, _release_year{year}, _artist{artist} {

}

Song::Song(const Song &s): _title{s._title}, _genre{s._genre}, _release_year{s._release_year}, _artist{s._artist} {

}

const std::string &Song::getTitle() const {
    return this->_title;
}

void Song::setTitle(const std::string &title) {
    this->_title = title;
}

const std::string &Song::getGenre() const {
    return this->_genre;
}

const std::string &Song::getArtist() const {
    return this->_artist;
}

const int Song::getReleaseYear() const {
    return this->_release_year;
}

void Song::setGenre(const std::string &genre) {
    this->_genre = genre;
}

void Song::setArtist(const std::string &artist) {
    this->_artist = artist;
}

void Song::setReleaseYear(int year) {
    this->_release_year = year;
}

Song &Song::operator=(const Song &song) {
    this->_title = song._title;
    this->_genre = song._genre;
    this->_artist = song._artist;
    this->_release_year = song._release_year;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Song &song) {
    os<<song._title<<" by "<<song._artist<<"\ngenre: " << song._genre <<"\nrelease year: " <<song._release_year<<std::endl;
    return os;
}
