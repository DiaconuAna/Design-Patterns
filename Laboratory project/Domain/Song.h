//
// Created by amina on 3/8/2023.
//

#ifndef LABORATORY_PROJECT_SONG_H
#define LABORATORY_PROJECT_SONG_H


#include <string>
#include <iostream>

class Song {
private:
    std::string _title;
    std::string _genre;
    int _release_year;
    std::string _artist;

public:
    Song();
    Song(const std::string&, const std::string&, int, const std::string&);
    Song(const Song& s);

    const std::string& getTitle() const;
    const std::string& getGenre() const;
    const std::string& getArtist() const;
    const int getReleaseYear() const;

    void setTitle(const std::string& title);
    void setGenre(const std::string& genre);
    void setArtist(const std::string& artist);
    void setReleaseYear(int year);

    Song& operator=(const Song& song);
    friend std::ostream& operator<<(std::ostream&, const Song&);

};


#endif //LABORATORY_PROJECT_SONG_H
