//
// Created by amina on 3/8/2023.
//

#ifndef LABORATORY_PROJECT_CSVREPOSITORY_H
#define LABORATORY_PROJECT_CSVREPOSITORY_H


#include "SongRepository.h"

class CSVRepository : public SongRepository{
private:
    void readFromFile();
    void writeToFile();
    std::string _filename;
    std::vector<Song> songs;
public:
    CSVRepository(const std::string& file_name);
    std::vector<Song> getSongs();

    void addSong(const Song& song);
    Song deleteSong(Song song);
    int searchSong(Song song);
    Song& getSong(int position);
    ~CSVRepository();
};


#endif //LABORATORY_PROJECT_CSVREPOSITORY_H
