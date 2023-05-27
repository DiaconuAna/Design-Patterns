//
// Created by amina on 3/9/2023.
//

#ifndef LABORATORY_PROJECT_ADDCOMMAND_H
#define LABORATORY_PROJECT_ADDCOMMAND_H

#include "ICommand.h"
#include "../Service/SongService.h"

class AddCommand : public ICommand{
private:
    SongService* service;
    Song song;
public:
    AddCommand(SongService &songService, Song s);
    void execute() override;
    void undo() override;
    void redo() override;
};


#endif //LABORATORY_PROJECT_ADDCOMMAND_H
