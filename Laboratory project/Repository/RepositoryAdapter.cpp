//
// Created by amina on 3/8/2023.
//

#include "RepositoryAdapter.h"

RepositoryAdapter::RepositoryAdapter(CSVRepository repo): userRepo{repo} {

}

void RepositoryAdapter::addSong(const Song &song) {
    this->userRepo.addSong(song);
}

Song RepositoryAdapter::deleteSong(Song song) {
    return this->userRepo.deleteSong(song);
}

int RepositoryAdapter::searchSong(Song song) {
    return this->userRepo.searchSong(song);
}

Song &RepositoryAdapter::getSong(int position) {
    return this->userRepo.getSong(position);
}

std::vector<Song> RepositoryAdapter::getSongs() {
    return this->userRepo.getSongs();
}
