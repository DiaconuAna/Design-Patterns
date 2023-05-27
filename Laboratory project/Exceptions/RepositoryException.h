//
// Created by amina on 3/9/2023.
//

#ifndef LABORATORY_PROJECT_REPOSITORYEXCEPTION_H
#define LABORATORY_PROJECT_REPOSITORYEXCEPTION_H

#include <exception>
#include <string>

class RepositoryException : public std::exception {
private: std::string _message;
public:
    RepositoryException(const std::string& message);
    const std::string& get_message() const;
};


#endif //LABORATORY_PROJECT_REPOSITORYEXCEPTION_H
