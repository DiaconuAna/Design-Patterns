//
// Created by amina on 3/8/2023.
//

#ifndef LABORATORY_PROJECT_MYLOGGER_H
#define LABORATORY_PROJECT_MYLOGGER_H

#include <mutex>
#include <fstream>

class MyLogger {
private:
    static MyLogger* logger;
    static std::mutex mtx;

protected:
    std::string output_;
    std::ofstream logfile;

    ~MyLogger();

public:
    MyLogger(MyLogger &other) = delete; // it cannot be cloned
    void operator=(const MyLogger& ) = delete; // it should not be assigned
    static MyLogger* getInstance();
    void logMessage(const std::string message);

    MyLogger();
    explicit MyLogger(const std::string file_name);
};


#endif //LABORATORY_PROJECT_MYLOGGER_H
