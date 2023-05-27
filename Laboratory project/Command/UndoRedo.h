//
// Created by amina on 3/9/2023.
//

#ifndef LABORATORY_PROJECT_UNDOREDO_H
#define LABORATORY_PROJECT_UNDOREDO_H

#include <stack>
#include <memory>
#include "ICommand.h"

typedef std::stack<std::shared_ptr<ICommand>> commandStack;

class UndoRedo {
private:
    commandStack undoStack;
    commandStack redoStack;

public:

    UndoRedo(){};
    void redo();
    void undo();

    void executeCommand(std::shared_ptr<ICommand> command);


};


#endif //LABORATORY_PROJECT_UNDOREDO_H
