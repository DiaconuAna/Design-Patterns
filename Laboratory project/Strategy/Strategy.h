//
// Created by amina on 3/10/2023.
//

#ifndef LABORATORY_PROJECT_STRATEGY_H
#define LABORATORY_PROJECT_STRATEGY_H


class Strategy {
public:
    virtual ~Strategy() = default;
    virtual std::vector<Song> filter(std::vector<Song> songs, std::string criteria) = 0;
};


#endif //LABORATORY_PROJECT_STRATEGY_H
