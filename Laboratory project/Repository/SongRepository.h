//
// Created by amina on 3/8/2023.
//

#ifndef LABORATORY_PROJECT_SONGREPOSITORY_H
#define LABORATORY_PROJECT_SONGREPOSITORY_H


#include <vector>
#include "../Domain/Song.h"

class SongRepository {
protected:
    std::vector<Song> song_repo;
public:
    SongRepository();

    virtual std::vector<Song> getSongs();

    virtual void addSong(const Song& song);
    virtual Song deleteSong(Song song);
    virtual int searchSong(Song song);
    virtual Song& getSong(int position);
};


#endif //LABORATORY_PROJECT_SONGREPOSITORY_H
