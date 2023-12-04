#include <iostream>
#include <set>
#include <string>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"

//Function declarations
void chooseFiles(std::set<std::string> filesToRead, std::string instruction); //TODO: maybe add a remove files option
void fillAll(std::set<std::string> fileToRead);
void pokemonSortMenu(Catalogue catalogue);

int main () {

    std::string direction = "?";
    std::set<std::string> chosenFiles;
    Catalogue pokemonCatalogue;

    std::cout << "Which Pokemon generations do you wish to include?" << std::endl;
    chooseFiles(chosenFiles, direction);

    pokemonSortMenu(pokemonCatalogue);

    return 0;

}


void chooseFiles(std::set<std::string> filesToRead, std::string instruction){ //instruction has already been initialised to an invalid value
    while (instruction != "F"){

        if (instruction == "A"){
            fillAll(filesToRead);
        } else if (instruction >= "1" && instruction <= "9") {
            std::string fileName = "Pokemon" + instruction + ".txt";
            filesToRead.insert(fileName);
        } else if (instruction == "E") {
                exit(0);
        }

        std::cout << "Enter a number (1-9), F to finish entering files, or E to exit the program." << std::endl;
        std::cin >> instruction;

    }
}

void fillAll(std::set<std::string> fileToRead){
    for (int i = 1; i < 10; i ++){
        std::string fileName = "Pokemon" + std::to_string(i) + ".txt";
        fileToRead.insert(fileName);
    }

}

void pokemonSortMenu(){



}
