//
// Created by amina on 3/8/2023.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "MyLogger.h"

MyLogger::MyLogger() {
    this->output_ = R"(../out/log.txt)";
}

MyLogger::MyLogger(const std::string file_name): output_{file_name}{
}

MyLogger::~MyLogger() {
    logfile.close();
}

MyLogger *MyLogger::getInstance() {
    std::lock_guard<std::mutex> lock(mtx);
    if(logger==nullptr){
        logger = new MyLogger();
    }
    return logger;
}

void MyLogger::logMessage(const std::string message) {
    logfile.open (this->output_, std::ios::app);
    if (!logfile) {
        std::cerr << "file open failed: " << std::strerror(errno) << "\n";
    }
    if(logfile.is_open()) {
        logfile << message + "\n";
    }
    else
        std::cout<<"fuck";
    logfile.close();
}

