cmake_minimum_required(VERSION 3.25)
project(Pokemon)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pokemon
        Pokemon.cpp
        Pokemon.h Catalogue.h PokemonCatalogue.cpp Catalogue.cpp Catalogue.cpp)
