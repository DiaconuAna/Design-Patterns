//
// Created by amina on 3/9/2023.
//

#ifndef LABORATORY_PROJECT_DELETECOMMAND_H
#define LABORATORY_PROJECT_DELETECOMMAND_H

#include "ICommand.h"
#include "../Service/SongService.h"

class DeleteCommand : public ICommand {
private:
    SongService* service;
    Song song;
public:
    DeleteCommand(SongService &songService, Song s);
    void execute() override;
    void undo() override;
    void redo() override;
};


#endif //LABORATORY_PROJECT_DELETECOMMAND_H
