//
// Created by amina on 3/10/2023.
//

#ifndef LABORATORY_PROJECT_FILTERBYRELEASEYEARSTRATEGY_H
#define LABORATORY_PROJECT_FILTERBYRELEASEYEARSTRATEGY_H


class FilterByReleaseYearStrategy : public Strategy{
public:
    std::vector<Song> filter(std::vector<Song> songs, std::string criteria) override{
        filter_logger->logMessage("Filter songs by release year: " + criteria);
        std::vector<Song> filtered;
        std::copy_if(songs.begin(), songs.end(), std::back_inserter(filtered), [&criteria](Song s) {
            return s.getReleaseYear() == stoi(criteria);
        });
        return filtered;
    }

};


#endif //LABORATORY_PROJECT_FILTERBYRELEASEYEARSTRATEGY_H
