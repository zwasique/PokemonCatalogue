#include <iostream>
#include <vector>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"

//void menu();

int main (int argc, char** argv) {
    if (argc <2){
        std::cerr << "Supply at least one Pokemon*.txt file";
    }


    std::vector<std::string> files;
    files.reserve(argc);
    for (int i = 0; i < argc; i++){
        files.emplace_back(argv[i]);}


}