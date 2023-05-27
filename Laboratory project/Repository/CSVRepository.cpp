//
// Created by amina on 3/8/2023.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include "CSVRepository.h"
#include "../Exceptions/RepositoryException.h"

CSVRepository::CSVRepository(const std::string &file_name): _filename{file_name} {
    this->readFromFile();
}

void CSVRepository::readFromFile() {
    std::string line, word;
    std::vector<std::string> row;

    std::fstream csv_file(this->_filename, std::ios::in);
    if(csv_file.is_open()){
        while(getline(csv_file, line)){
            row.clear();
            std::stringstream str(line);
            while(getline(str, word, ','))
                row.push_back(word);
//            std::cout<<row[0]<<" "<<row[1]<< " "<<stoi(row[2])<<" " << row[3]<<std::endl;
            this->songs.emplace_back(row[0], row[1], stoi(row[2]), row[3]);
        }
    }

}

void CSVRepository::writeToFile() {
    std::fstream file(this->_filename.c_str(), std::ios::out|std::ios::trunc);

    if (file.is_open()){
        std::vector<Song> list = this->getSongs();
        for(const auto& song: list){
            file<<song.getTitle()<<","<<song.getGenre()<<","<<song.getReleaseYear()<<","<<song.getArtist()<<"\n";
        }
    }
    else {
        std::cerr << "file open failed: " << std::strerror(errno) << "\n";
        //throw Exception("Unable to open the file!\n");
    }
}

std::vector<Song> CSVRepository::getSongs() {
    return this->songs;
}

void CSVRepository::addSong(const Song &song) {
    this->songs.push_back(song);
    this->writeToFile();
}

Song CSVRepository::deleteSong(Song song) {
    int song_position = this->searchSong(song);
    if(song_position == -1)
        throw RepositoryException("Item " + song.getTitle() + " not found. Delete failed!");
    else {
        this->songs.erase(songs.begin() + song_position);
        this->writeToFile();
        return song;
    }
}

int CSVRepository::searchSong(Song song) {
    int i=0;
    for(const auto& s: this->songs){
        if(s.getTitle() == song.getTitle()){
            return i;
        }
        i++;
    }
    return -1;}

Song &CSVRepository::getSong(int position) {
    return this->songs[position];
}

CSVRepository::~CSVRepository() {

}
