//
// Created by amina on 3/8/2023.
//

#ifndef LABORATORY_PROJECT_UI_H
#define LABORATORY_PROJECT_UI_H


#include "../Service/SongService.h"
#include "../Iterator/Iterator.h"
#include "../Command/UndoRedo.h"
#include "../Strategy/Filter.h"

class UI {
private:
    SongService& _service;
    UndoRedo& _undoredo;
    Filter filter;
public:
    UI(SongService& service, UndoRedo& ur);
    void printMenu();
    void menu();
    void addSong();
    void removeSong();
    void listSongs();
    void undo();
    void redo();
    void filterByGenre();
    void filterByArtist();
    void filterByReleaseYear();

};


#endif //LABORATORY_PROJECT_UI_H
