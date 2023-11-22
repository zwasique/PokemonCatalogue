cmake_minimum_required(VERSION 3.25)
project(PokemonCatalogue)

set(CMAKE_CXX_STANDARD 14)

target_include_directories(PokemonCatalogue PRIVATE ../include)

add_executable(PokemonCatalogue
        PokemonCatalogue.cpp
        Pokemon.h Catalogue.h Pokemon.cpp Catalogue.cpp)

set_target_properties(PokemonCatalogue PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO

)
