//
// Created by amina on 3/9/2023.
//

#include <iostream>
#include <cstring>
#include "UndoRedo.h"
#include "../Exceptions/UndoRedoException.h"

void UndoRedo::redo() {
    if(this->redoStack.size()<=0){
        throw UndoRedoException{"No more redos"};
    }
    this->redoStack.top()->redo();
    this->undoStack.push(this->redoStack.top());
    this->redoStack.pop();
}

void UndoRedo::undo() {
    if(this->undoStack.size() <= 0){
        throw UndoRedoException{"No more undos"};
    }
    this->undoStack.top()->undo();
    this->redoStack.push(this->undoStack.top());
    this->undoStack.pop();
}

void UndoRedo::executeCommand(std::shared_ptr<ICommand> command) {
    this->redoStack = commandStack();
    command->execute();
    this->undoStack.push(command);
}
