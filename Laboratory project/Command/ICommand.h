//
// Created by amina on 3/9/2023.
//

#ifndef LABORATORY_PROJECT_ICOMMAND_H
#define LABORATORY_PROJECT_ICOMMAND_H

#include <vector>

class ICommand {
public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual void redo()=0;
};


#endif //LABORATORY_PROJECT_ICOMMAND_H
