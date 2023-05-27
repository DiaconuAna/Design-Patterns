//
// Created by amina on 3/10/2023.
//

#ifndef LABORATORY_PROJECT_FILTER_H
#define LABORATORY_PROJECT_FILTER_H

#include "Strategy.h"

class Filter {
public:
    Filter()= default;

    explicit Filter(Strategy* s){
        filter_strategy = s;
    }

    std::vector<Song> filter(std::vector<Song> songs, std::string criteria){
        return filter_strategy->filter(songs, criteria);
    }

    void setStrategy(Strategy* strategy){
        filter_strategy = strategy;
    }

private:
    Strategy* filter_strategy;

};


#endif //LABORATORY_PROJECT_FILTER_H
