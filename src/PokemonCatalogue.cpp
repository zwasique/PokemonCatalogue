#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"

#define MAGENTA_TEXT "\033[0;35m"

#define YELLOW_TEXT "\033[0;33m"

#define RESET_TEXT "\033[0m"


//Function declarations
void chooseFiles(std::set<std::string> filesToRead, std::string instruction); //maybe add a remove files option
void fillAll(std::set<std::string> fileToRead);
void pokemonSortMenu(const Catalogue& catalogue, std::string instruction);

int main () {

    std::string direction = "?";
    std::set<std::string> chosenFiles;
    Catalogue pokemonCatalogue;


    std::cout << MAGENTA_TEXT << "Which Pokemon generations do you wish to include?" << RESET_TEXT << "\n";
    chooseFiles(chosenFiles, direction);
    for (auto it = chosenFiles.begin(); it != chosenFiles.end(); ++it){
        std:: cout << *it << " ";
    }
    std::cerr << "\n";

    pokemonCatalogue.fillCatalogue(chosenFiles);

    std::cout << std::endl;
    std::cout << YELLOW_TEXT << "Now you can display Pokemon. How would you like to sort them?" << RESET_TEXT << "\n";

    pokemonSortMenu(pokemonCatalogue, direction);

    return 0;

}


void chooseFiles(std::set<std::string> filesToRead, std::string instruction){ //instruction has already been initialised to an invalid value
    while (instruction != "C"){

        if (instruction == "A"){
            fillAll(filesToRead);
            return;
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


}

void fillAll(std::set<std::string> fileToRead){
    std::cerr<< "void fillAll(set<string> fileToRead)\n";
    for (int i = 1; i < 10; i ++){
        std::string fileName = "Pokemon" + std::to_string(i) + ".txt";
        fileToRead.insert(fileName);
    }

}

void pokemonSortMenu(const Catalogue& catalogue, std::string instruction){
    
    while (instruction != "E") {

            if (instruction == "G") //list Pokémon by numerical order
                std::cout << catalogue;
            else if (instruction == "A") //sort Pokemon alphabetically by name
                catalogue.sortAlpha();
            else if (instruction == "T") //see all Pokemon of a type, or organise by type
                catalogue.sortType();
            else if (instruction == "E")
                exit(0);

            std::cout << "Enter G to sort by generation, T to sort by type, and A to sort alphabetically, and E to exit: ";
            std::cin >> instruction;


         }

    }
