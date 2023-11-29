#include <iostream>
#include <set>
#include <string>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"

//Function declarations
void chooseFiles(std::set<std::string> filesToRead, char instruction);
void pokemonSortMenu(Catalogue catalogue);
void chooseFiles2(std::set<std::string> filesToRead, char instruction);

int main () {

    char direction = '?';
    std::set<std::string> chosenFiles;
    Catalogue pokemonCatalogue;

    chooseFiles(chosenFiles, direction);
    chooseFiles2(chosenFiles, direction);
    pokemonSortMenu(pokemonCatalogue);


    return 0;



}


//Function definitions

void readFiles(std::set<std::string> filesToRead, char instruction) {

    std::cout << "Which Pokemon generations do you wish to include?"
                 "Enter a number (1-9), F to finish entering, or E to exit the program: " << std::endl;
    std::cin >> instruction;

    while ((instruction >= '1' && instruction <= '9') || instruction == 'F' || instruction == 'E') {
        if (instruction == 'E') {
            exit(0);
        }
        while (instruction >= '1' && instruction <= '9') {
            std::string fileName = "Pokemon" + std::string(reinterpret_cast<const char *>(instruction)) + ".txt";
            filesToRead.insert(fileName);

            std::cout << "Enter a number (1-9), F to finish entering files, or E to exit the program." << std::endl;
            std::cin >> instruction;
        }
    }

    return;
}


void readFiles2(std::set<std::string> filesToRead, char instruction){ //instruction has already been initialised to an invalid value
    //before function: std::cout << "Which Pokemon generations do you wish to include?"
    while (instruction != 'F'){

        if (instruction == 'E'){
            exit(0);
        } else if (instruction >= '1' && instruction <= '9') {
            std::string fileName = "Pokemon" + std::string(reinterpret_cast<const char *>(instruction)) + ".txt";
            filesToRead.insert(fileName);
        }

        std::cout << "Enter a number (1-9), F to finish entering files, or E to exit the program." << std::endl;
        std::cin >> instruction;
    }
    return;
}



void pokemonSortMenu(){

    std::cout << "temp" << std::endl;

    return;


}
