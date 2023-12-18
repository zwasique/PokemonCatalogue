#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"

//Function declarations
std::set<std::string> chooseFiles(std::set<std::string> filesToRead, std::string instruction); //maybe add a remove files option
void fillAll(std::set<std::string> fileToRead);
void pokemonSortMenu(const Catalogue& catalogue, std::string instruction);

int main () {

    std::string direction = "?";
    std::set<std::string> chosenFiles;
    Catalogue pokemonCatalogue;

    std::cout << "Which Pokemon generations do you wish to include?" << std::endl;
    chooseFiles(chosenFiles, direction);

    pokemonCatalogue.fillCatalogue(chosenFiles);

    pokemonSortMenu(pokemonCatalogue, direction);

    return 0;

}


std::set<std::string> chooseFiles(std::set<std::string> filesToRead, std::string instruction){ //instruction has already been initialised to an invalid value
    while (instruction != "C"){

        if (instruction == "A"){
            fillAll(filesToRead);
            break;
        } else if (instruction >= "1" && instruction <= "9") {
            std::string fileName = "Pokemon" + instruction + ".txt";
            filesToRead.insert(fileName);
        } else if (instruction == "E") {
                exit(0);
        }

        std::cout << "Enter a generation number 1-9, A to add all files, C to continue, or E to exit the program: ";
        std::cin >> instruction;
        std::cout << "\n";

    }
    return filesToRead;
}

void fillAll(std::set<std::string> fileToRead){
    for (int i = 1; i < 10; i ++){
        std::string fileName = "Pokemon" + std::to_string(i) + ".txt";
        fileToRead.insert(fileName);
    }

}

void pokemonSortMenu(const Catalogue& catalogue, std::string instruction){
    
    while (instruction != "E") {

            if (instruction == "N") //list Pokémon by numerical order
                std::cout << catalogue;
            else if (instruction == "A") //sort Pokemon alphabetically by name
                catalogue.sortAlpha();
            else if (instruction == "T") //see all Pokemon of a type, or organise by type
                catalogue.sortType();
            else if (instruction == "E")
                exit(0);

            std::cout << "Enter G to sort by generation, T to sort by type, and A to sort alphabetically, and E to exit: ";
            std::cin >> instruction;
            std::cout << "\n";


         }

    }
