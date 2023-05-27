//
// Created by amina on 3/13/2023.
//

#ifndef LABORATORY_PROJECT_TESTS_H
#define LABORATORY_PROJECT_TESTS_H

#include <cassert>
#include <iostream>
#include "../Command/UndoRedo.h"
#include "../Service/SongService.h"

class Tests {
private:
    SongService& _service;
    UndoRedo& _undoredo;

public:
    Tests(SongService& service, UndoRedo& ur);
    void testAll();
};



#endif //LABORATORY_PROJECT_TESTS_H
