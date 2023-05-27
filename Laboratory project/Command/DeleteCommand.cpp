//
// Created by amina on 3/9/2023.
//

#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(SongService &songService, Song s): service{&songService}, song{s} {

}

void DeleteCommand::execute() {
    this->service->removeSong(this->song, 0);
}

void DeleteCommand::undo() {
    this->service->addSong(song.getTitle(), song.getGenre(), song.getReleaseYear(), song.getArtist(), 1);
}

void DeleteCommand::redo() {
    this->service->removeSong(this->song, 2);
}
