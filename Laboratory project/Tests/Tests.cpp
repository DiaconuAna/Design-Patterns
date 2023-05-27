//
// Created by amina on 3/13/2023.
//

#include "Tests.h"
#include "../Repository/CSVRepository.h"
#include "../Repository/RepositoryAdapter.h"
#include "../Service/SongService.h"
#include "../Command/UndoRedo.h"
#include "../Exceptions/RepositoryException.h"

Tests::Tests(SongService &service, UndoRedo &ur): _service{service}, _undoredo{ur} {
    this->testAll();
}


void Tests::testAll() {
    std::vector<Song> mySongs = this->_service.getSongList();
    bool exceptionThrown = false;
    assert(mySongs.size() == 2);
    // add a song
    this->_service.addSong("Song1", "pop", 2020, "me", 0);
    mySongs = this->_service.getSongList();
    assert(mySongs.size() == 3);
    this->_service.removeSong(Song("Song1", "pop", 2020, "me"), 0);
    mySongs = this->_service.getSongList();
    assert(mySongs.size() == 2);
    // try to delete a non-existent song
    try{
        this->_service.removeSong(Song("Song1", "pop", 2020, "me"), 0);
    }
    catch (RepositoryException& e){
        exceptionThrown = true;
    }
    assert(exceptionThrown);
}

