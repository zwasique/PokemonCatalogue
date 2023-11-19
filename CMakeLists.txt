cmake_minimum_required(VERSION 3.25)
project(PokémonCatalogue)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PokemonCatalogue
        PokemonCatalogue.cpp
        Pokemon.h Catalogue.h Pokemon.cpp Catalogue.cpp)
