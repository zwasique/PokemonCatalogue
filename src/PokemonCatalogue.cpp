#include <iostream>
#include <set>
#include <string>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"

//Function declarations
void readFiles(std::set<std::string> filesToRead, char instruction, Catalogue catalogue);
void pokemonSortMenu(Catalogue catalogue);

int main () {

    char direction = '?';
    std::set<std::string> chosenFiles;
    Catalogue pokemonCatalogue;

    readFiles(chosenFiles, direction, pokemonCatalogue);
    pokemonSortMenu(pokemonCatalogue);



}


void readFiles(std::set<std::string> filesToRead, char instruction, Catalogue catalogue){

    std::cout << "Which Pokemon generations do you wish to include?"
                 "Enter a number (1-9), F to finish entering, or E to exit the program: " << std::endl;

    std::cin >> instruction;

    while ((instruction >= '1' && instruction <= '9') ||instruction == 'F' || instruction == 'E'){
        if (instruction == 'E'){
            exit(0);}

        while (instruction >= '1' && instruction <= '9'){
            std::string fileName = "Pokemon" + std::string(reinterpret_cast<const char *>(instruction)) + ".txt";
            filesToRead.insert(fileName);

            std::cout << "Enter a number (1-9), F to finish entering files, or E to exit the program." << std::endl;
            std::cin >> instruction;
        }
    }




}

void pokemonSortMenu(){

    std::cout << "temp" << std::endl;



}
//Function definitions