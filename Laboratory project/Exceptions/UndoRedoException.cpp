//
// Created by amina on 3/9/2023.
//

#include "UndoRedoException.h"

UndoRedoException::UndoRedoException(const std::string &msg): std::exception(), _msg{msg} {

}

const std::string &UndoRedoException::get_message() const {
    return this->_msg;
}
