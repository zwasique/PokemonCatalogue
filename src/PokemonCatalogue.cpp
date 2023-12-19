#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include "../include/Pokemon.h"
#include "../include/Catalogue.h"


#define MAGENTA_TEXT "\033[38;5;200m"


#define WHITE_TEXT "\033[1;37m"
#define YELLOW_TEXT "\033[38;5;220m"


#define RESET_TEXT "\033[0m"


//Function declarations
std::set<std::string> chooseFiles(std::set<std::string>& filesToRead, std::string instruction); //maybe add a remove files option
void fillAll(std::set<std::string>& fileToRead);
void pokemonSortMenu(const Catalogue& catalogue, std::string instruction);

int main () {

    std::string direction = "?";
    std::set<std::string> chosenFiles;
    Catalogue pokemonCatalogue;


    std::cout << MAGENTA_TEXT << "Which Pokemon generations do you wish to include?" << "\n" << WHITE_TEXT;
    chooseFiles(chosenFiles, direction);
    std::cout << RESET_TEXT;


    pokemonCatalogue.fillCatalogue(chosenFiles);

    std::cout << std::endl;
    std::cout << YELLOW_TEXT << "Now you can display Pokemon. How would you like to sort them?"  << "\n" << WHITE_TEXT;
    pokemonSortMenu(pokemonCatalogue, direction);
    std::cout << RESET_TEXT;

    return 0;

}


std::set<std::string> chooseFiles(std::set<std::string>& filesToRead, std::string instruction){ //instruction has already been initialised to an invalid value
    //std::cerr << MAGENTA_TEXT<< "void chooseFiles(std::set<std::string> filesToRead, std::string instruction)\n"<< RESET_TEXT;
    while (instruction != "C"){

        if (instruction == "A"){
            fillAll(filesToRead);

            return filesToRead;
        } else if (instruction >= "1" && instruction <= "9") {
            std::string fileName = "Pokemon" + instruction + ".txt";
        //    std::cerr << MAGENTA_TEXT<< "added" << fileName << "\n"<< RESET_TEXT;
            filesToRead.insert(fileName);
        } else if (instruction == "E") {
                exit(0);
        }

        std::cout << "Enter a generation number 1-9, A to add all files, C to continue, or E to exit the program: ";
        std::cin >> instruction;
        std::cout << "\n";

    }
    //std::cerr << "\n" << MAGENTA_TEXT<< "The current size of chosenFiles is " << filesToRead.size() << RESET_TEXT<<"\n";
    return filesToRead;
}

void fillAll(std::set<std::string>& fileToRead){
    //std::cerr<< MAGENTA_TEXT<< "void fillAll(set<string> fileToRead)\n"<< RESET_TEXT;
    std::string fileName = "file";
    for (int i = 1; i < 10; i ++){
        fileName = "Pokemon" + std::to_string(i) + ".txt";
    //    std::cerr << MAGENTA_TEXT<< "added" << fileName << "\n"<< RESET_TEXT;
        fileToRead.insert(fileName);
    }

}

void pokemonSortMenu(const Catalogue& catalogue, std::string instruction){
    //std::cerr << MAGENTA_TEXT<< "void pokemonSortMenu(const Catalogue& catalogue, std::string instruction)\n"<< RESET_TEXT;
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
