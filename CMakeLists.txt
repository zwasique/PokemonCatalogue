cmake_minimum_required(VERSION 3.27)

project(PokemonCatalogue)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/../build)

# Collect source files
set(SOURCES
       	src/PokemonCatalogue.cpp
        src/Pokemon.cpp
        src/Catalogue.cpp)

add_executable(PokemonCatalogue ${SOURCES})

target_include_directories(PokemonCatalogue PRIVATE 
${CMAKE_SOURCE_DIR}/../include)

set_target_properties(PokemonCatalogue PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

