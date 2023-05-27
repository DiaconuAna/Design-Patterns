//
// Created by amina on 3/9/2023.
//

#include "RepositoryException.h"

RepositoryException::RepositoryException(const std::string &message): std::exception(), _message{message} {

}

const std::string &RepositoryException::get_message() const {
    return this->_message;
}
