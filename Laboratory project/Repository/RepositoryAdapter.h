//
// Created by amina on 3/8/2023.
//

#ifndef LABORATORY_PROJECT_REPOSITORYADAPTER_H
#define LABORATORY_PROJECT_REPOSITORYADAPTER_H


#include "SongRepository.h"
#include "CSVRepository.h"

class RepositoryAdapter : public SongRepository {
private:
    CSVRepository userRepo;
public:
    RepositoryAdapter(CSVRepository repo);
    virtual std::vector<Song> getSongs();

    void addSong(const Song& song);
    Song deleteSong(Song song);
    int searchSong(Song song);
    Song& getSong(int position);
};


#endif //LABORATORY_PROJECT_REPOSITORYADAPTER_H
