//
// Created by amina on 3/10/2023.
//

#ifndef LABORATORY_PROJECT_FILTERBYGENRESTRATEGY_H
#define LABORATORY_PROJECT_FILTERBYGENRESTRATEGY_H

#include <algorithm>
#include <MyLogger.h>
#include "Strategy.h"

//MyLogger* filter_logger = MyLogger::getInstance(R"(D:\Uni documents\Sem6\Design Patterns\Laboratory project\out\log.txt)");
MyLogger* filter_logger = MyLogger::getInstance();

class FilterByGenreStrategy : public Strategy {
public:
    std::vector<Song> filter(std::vector<Song> songs, std::string criteria) override{
        filter_logger->logMessage("Filter songs by genre " + criteria);
        std::vector<Song> filtered;
        std::copy_if(songs.begin(), songs.end(), std::back_inserter(filtered), [&criteria](Song s) {
            return s.getGenre() == criteria;
        });
        return filtered;
    }
};


#endif //LABORATORY_PROJECT_FILTERBYGENRESTRATEGY_H
