#include <iostream>
#include "MyLogger.h"
#include "Repository/SongRepository.h"
#include "Service/SongService.h"
#include "Tests/Tests.h"
#include "UI/UI.h"
#include "Repository/RepositoryAdapter.h"

//Singleton* Singleton::pinstance_{nullptr};
//std::mutex Singleton::mutex_;
//MyLogger* MyLogger::logger{nullptr};
//std::mutex MyLogger::mtx;

//MyLogger* logger = new MyLogger("out/log.txt");

int main() {
//    SongRepository songRepo{};
    CSVRepository userRepo{R"(..\data\test_songs.csv)"};
    RepositoryAdapter repo{userRepo};
    SongService service{repo};
    UndoRedo undoredo{};

    Tests t{service, undoredo};
//    UI ui{service, undoredo};
//    ui.menu();

    return 0;
}

