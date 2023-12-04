#include <iostream>
#include <set>
#include <string>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"

//Function declarations
void chooseFiles(std::set<std::string> filesToRead, char instruction);
void pokemonSortMenu(Catalogue catalogue);

int main () {

    char direction = '?';
    std::set<std::string> chosenFiles;
    Catalogue pokemonCatalogue;

    std::cout << "Which Pokemon generations do you wish to include?" << std::endl;
    chooseFiles(chosenFiles, direction);

    pokemonSortMenu(pokemonCatalogue);

    return 0;


}



void chooseFiles(std::set<std::string> filesToRead, char instruction){ //instruction has already been initialised to an invalid value
    while (instruction != 'F'){

        if (instruction == 'E'){
            exit(0);
        } else if (instruction >= '1' && instruction <= '9') {
            std::string fileName = "Pokemon" + std::string(reinterpret_cast<const char *>(instruction)) + ".txt";
            filesToRead.insert(fileName);
        }

        std::cout << "Enter a number (1-9), F to finish entering files, or E to exit the program." << std::endl;
        std::cin >> instruction;

        //maybe: add remove files option
    }

}


void pokemonSortMenu(){



}
