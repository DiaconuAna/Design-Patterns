//
// Created by amina on 3/8/2023.
//

#include "SongRepository.h"

SongRepository::SongRepository() {

}

std::vector<Song> SongRepository::getSongs() {
    return this->song_repo;
}

void SongRepository::addSong(const Song &song) {
    this->song_repo.push_back(song);
}

Song SongRepository::deleteSong(Song song) {
    int song_position = this->searchSong(song);
    this->song_repo.erase(song_repo.begin() + song_position);
    return song;
}

int SongRepository::searchSong(Song song) {
    int i=0;
    for(const auto& s: this->song_repo){
        if(s.getTitle() == song.getTitle()){
            return i;
        }
        i++;
    }
    return -1;
}

Song &SongRepository::getSong(int position) {
    return this->song_repo[position];
}
