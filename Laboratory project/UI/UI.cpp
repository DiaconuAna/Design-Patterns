//
// Created by amina on 3/8/2023.
//

#include <iostream>
#include <cstring>
#include "UI.h"
#include "../Command/AddCommand.h"
#include "../Command/DeleteCommand.h"
#include "../Exceptions/UndoRedoException.h"
#include "../Strategy/FilterByGenreStrategy.h"
#include "../Strategy/FilterByArtistStrategy.h"
#include "../Strategy/FilterByReleaseYearStrategy.h"
#include "../Exceptions/RepositoryException.h"

UI::UI(SongService &service, UndoRedo& ur): _service{service}, _undoredo{ur} {
    this->filter = Filter();
}

void UI::printMenu() {
    std::cout<< std::endl;
    std::cout<<"0. Exit.\n";
    std::cout<<"1. List all songs.\n";
    std::cout<<"2. Add a song.\n";
    std::cout<<"3. Remove a song from the list.\n";
    std::cout<<"4. Filter by genre.\n";
    std::cout<<"5. Filter by artist.\n";
    std::cout<<"6. Filter by release year.\n";
    std::cout<<"7. Undo.\n";
    std::cout<<"8. Redo.\n";
    std::cout<<std::endl;
}

void UI::menu() {
    int command, over = 0;
    std::cout << "Welcome!\n";

    while(!over){
        printMenu();
        std::cout<<"Your command>> ";
        std::cin>>command;
        switch(int(command)){
            case 0:
                over = 1;
                std::cout<<"Goodbye!\n";
                break;
            case 1:
                this->listSongs();
                break;
            case 2:
                this->addSong();
                break;
            case 3:
                try {
                    this->removeSong();
                }
                catch(const RepositoryException &e){
                    std::cerr << e.get_message() << "\n";
                }
                break;
            case 4:
                this->filterByGenre();
                break;
            case 5:
                this->filterByArtist();
                break;
            case 6:
                this->filterByReleaseYear();
                break;
            case 7:
                try {
                    this->undo();
                }
                catch(const UndoRedoException &e){
                    std::cerr << e.get_message() << "\n";
                }
                break;
            case 8:
                try {
                    this->redo();
                }
                catch(const UndoRedoException &e){
                    std::cerr << e.get_message() << "\n";
                }
                break;
            default: std::cout << "Please input a valid command! ";
        }
    }
}

void UI::addSong() {
    char stryear[100];
    std::string title, genre, artist;
    int year;

    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);

    std::cout << "Choose a genre: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, genre);

    std::cout<<"Choose an artist: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, artist);

    do {
        std::cout << "Year of release: ";
        std::cin.clear(); std::cin.sync();
        std::cin.get(stryear, 99);
        std::cin.clear(); std::cin.sync();
        year = atoi(stryear);
    }
    while (year == 0);

    Song song = Song{title, genre, year, artist};
    std::shared_ptr<ICommand> cmd(new AddCommand{this->_service, song});
    this->_undoredo.executeCommand(cmd);
//    this->_service.addSong(title, genre, year, artist);
}

void UI::removeSong() {
    std::string title;
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);

    Song song = this->_service.getSong(this->_service.searchPosition(Song{title, "", 0, ""}));
    std::shared_ptr<ICommand> cmd(new DeleteCommand{this->_service, song});
    this->_undoredo.executeCommand(cmd);
//    this->_service.removeSong(Song(title, "",0,""));
}

void UI::listSongs() {
    // iterator design pattern
    std::vector<Song> songList = this->_service.getSongList();
    Container<Song> songs_iterated;
    for(int i=0;i<songList.size();i++){
        songs_iterated.add(songList[i]);
    }

    auto* song_iterator = songs_iterated.createIterator();

    for(song_iterator->first(); song_iterator->hasNext(); song_iterator->next()){
        auto song = *song_iterator->current();
        std::cout<< song<<std::endl;
    }

}

void UI::undo() {
    this->_undoredo.undo();
}

void UI::redo() {
    this->_undoredo.redo();
}

void UI::filterByGenre() {
    std::string genre;
    std::cout << "Choose a genre: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, genre);

    FilterByGenreStrategy strategy;
    this->filter.setStrategy(&strategy);
    std::vector<Song> filter_results = this->filter.filter(this->_service.getSongList(), genre);
    if(!filter_results.empty()){
        for(const auto& s: filter_results){
            std::cout<<s<<std::endl;
        }
    }
    else{
        std::cout<<"There are no songs for the given genre : " << genre;
    }
}

void UI::filterByArtist() {
    std::string artist;
    std::cout << "Choose an artist: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, artist);

    FilterByArtistStrategy strategy;
    this->filter.setStrategy(&strategy);
    std::vector<Song> filter_results = this->filter.filter(this->_service.getSongList(), artist);
    if(!filter_results.empty()){
        for(const auto& s: filter_results){
            std::cout<<s<<std::endl;
        }
    }
    else{
        std::cout<<"The artist " << artist << " has no songs in this playlist";
    }
}

void UI::filterByReleaseYear() {
    char stryear[100];
    int year;

    do {
        std::cout << "Year of release: ";
        std::cin.clear(); std::cin.sync();
        std::cin.get(stryear, 99);
        std::cin.clear(); std::cin.sync();
        year = atoi(stryear);
    }
    while (year == 0);

    FilterByReleaseYearStrategy strategy;
    this->filter.setStrategy(&strategy);
    std::vector<Song> filter_results = this->filter.filter(this->_service.getSongList(), std::to_string(year));
    if(!filter_results.empty()){
        for(const auto& s: filter_results){
            std::cout<<s<<std::endl;
        }
    }
    else{
        std::cout<<"The playlist contains no songs released in "<< year;
    }
}

