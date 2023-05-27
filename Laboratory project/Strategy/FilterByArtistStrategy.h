//
// Created by amina on 3/10/2023.
//

#ifndef LABORATORY_PROJECT_FILTERBYARTISTSTRATEGY_H
#define LABORATORY_PROJECT_FILTERBYARTISTSTRATEGY_H

#include <algorithm>
#include "Strategy.h"

class FilterByArtistStrategy : public Strategy {
public:
    std::vector<Song> filter(std::vector<Song> songs, std::string criteria){
        filter_logger->logMessage("Filter songs by artist " + criteria);
        std::vector<Song> filtered;
        std::copy_if(songs.begin(), songs.end(), std::back_inserter(filtered), [&criteria](Song s) {
            return s.getArtist() == criteria;
        });
        return filtered;
    }
};


#endif //LABORATORY_PROJECT_FILTERBYARTISTSTRATEGY_H
