//
// Created by amina on 3/9/2023.
//

#ifndef LABORATORY_PROJECT_UNDOREDOEXCEPTION_H
#define LABORATORY_PROJECT_UNDOREDOEXCEPTION_H

#include <exception>
#include <string>

class UndoRedoException : public std::exception {
private:
    std::string _msg;
public:
    UndoRedoException(const std::string& msg);
    const std::string& get_message() const;

};

#endif //LABORATORY_PROJECT_UNDOREDOEXCEPTION_H
