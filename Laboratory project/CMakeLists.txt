cmake_minimum_required(VERSION 3.20)
project(Laboratory_project)

set(CMAKE_CXX_STANDARD 14)
include_directories(Logger/)
link_directories(Logger/)
add_executable(Laboratory_project main.cpp Domain/Song.cpp Domain/Song.h Logger/MyLogger.cpp Logger/MyLogger.h Repository/SongRepository.cpp Repository/SongRepository.h Service/SongService.cpp Service/SongService.h UI/UI.cpp UI/UI.h Repository/CSVRepository.cpp Repository/CSVRepository.h Repository/RepositoryAdapter.cpp Repository/RepositoryAdapter.h Iterator/Iterator.h Command/ICommand.h Command/AddCommand.cpp Command/AddCommand.h Command/UndoRedo.cpp Command/UndoRedo.h Command/DeleteCommand.cpp Command/DeleteCommand.h Exceptions/RepositoryException.cpp Exceptions/RepositoryException.h Exceptions/UndoRedoException.cpp Exceptions/UndoRedoException.h Strategy/Strategy.h Strategy/FilterByGenreStrategy.h Strategy/FilterByArtistStrategy.h Strategy/Filter.h Strategy/FilterByReleaseYearStrategy.h Tests/Tests.cpp Tests/Tests.h)
