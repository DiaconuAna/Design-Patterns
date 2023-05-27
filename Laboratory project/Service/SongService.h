//
// Created by amina on 3/8/2023.
//

#ifndef LABORATORY_PROJECT_SONGSERVICE_H
#define LABORATORY_PROJECT_SONGSERVICE_H


#include "../Repository/SongRepository.h"

class SongService {
private:
    SongRepository* _song_repo;
public:
    explicit SongService(SongRepository& songRepository);
    std::vector<Song> getSongList();
    void addSong(const std::string& title, const std::string& genre, int year, const std::string& artist, int flag);
    void removeSong(Song song, int flag);
    int searchPosition(Song song);
    Song getSong(int position);

};


#endif //LABORATORY_PROJECT_SONGSERVICE_H
