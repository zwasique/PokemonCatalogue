cmake_minimum_required(VERSION 3.25)

project(PokemonCatalogue)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

# Collect source files
set(SOURCES
       	src/PokemonCatalogue.cpp
        src/Pokemon.cpp
        src/Catalogue.cpp)

add_executable(PokemonCatalogue ${SOURCES})

target_include_directories(PokemonCatalogue PRIVATE 
${CMAKE_SOURCE_DIR}/../include)

set_target_properties(PokemonCatalogue PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

add_custom_target(clean_up
	DEPENDS PokemonCatalogue
	COMMAND ${CMAKE_COMMAND} -E echo "Cleaning up..."
	COMMAND ${CMAKE_SOURCE_DIR}/clean.sh
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PokemonCatalogue)
