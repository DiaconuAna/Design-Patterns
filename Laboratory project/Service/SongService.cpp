//
// Created by amina on 3/8/2023.
//

#include <MyLogger.h>
#include "SongService.h"

MyLogger* logger = MyLogger::getInstance();
//MyLogger* logger = MyLogger::getInstance(R"(D:\Uni documents\Sem6\Design Patterns\Laboratory project\out\log.txt)");
MyLogger* MyLogger::logger{nullptr};
std::mutex MyLogger::mtx;

SongService::SongService(SongRepository &songRepository) : _song_repo{&songRepository} {

}

void SongService::addSong(const std::string &title, const std::string &genre, int year, const std::string &artist, int flag) {
    switch(flag) {
        case 0:
            logger->logMessage("Add song " + title);
            break;
        case 1:
            logger->logMessage("Undo: Add song " + title);
            break;
        case 2:
            logger->logMessage("Redo: Add song " + title);
            break;
    }
    this->_song_repo->addSong(Song(title, genre, year, artist));
}

void SongService::removeSong(Song song, int flag) {
    switch(flag) {
        case 0:
            logger->logMessage("Delete song " + song.getTitle());
            break;
        case 1:
            logger->logMessage("Undo: Delete song " + song.getTitle());
            break;
        case 2:
            logger->logMessage("Redo: Delete song " + song.getTitle());
            break;
    }
    this->_song_repo->deleteSong(song);
}

int SongService::searchPosition(Song song) {
    logger->logMessage("Search position for song " + song.getTitle());
    return this->_song_repo->searchSong(song);
}

Song SongService::getSong(int position) {
    logger->logMessage("Get song from position "  + std::to_string(position));
    return this->_song_repo->getSong(position);
}

std::vector<Song> SongService::getSongList() {
    logger->logMessage("List all songs");
    return this->_song_repo->getSongs();
}
