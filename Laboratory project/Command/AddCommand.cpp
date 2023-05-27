//
// Created by amina on 3/9/2023.
//

#include "AddCommand.h"

AddCommand::AddCommand(SongService &songService, Song s): service{&songService}, song{s} {

}

void AddCommand::execute() {
    this->service->addSong(song.getTitle(), song.getGenre(), song.getReleaseYear(), song.getArtist(), 0);
}

void AddCommand::undo() {
    this->service->removeSong(this->song, 1);

}

void AddCommand::redo() {
    this->service->addSong(song.getTitle(), song.getGenre(), song.getReleaseYear(), song.getArtist(), 2);

}
