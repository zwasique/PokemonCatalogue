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

    std::cout << MAGENTA_TEXT << "Which Pokemon generations do you wish to include?\n" << WHITE_TEXT;
    chooseFiles(chosenFiles, direction);
    std::cout << RESET_TEXT;

    pokemonCatalogue.fillCatalogue(chosenFiles);


    std::cout << std::endl;
    std::cout << YELLOW_TEXT << "Now you can display Pokemon. How would you like to sort them?\n" << WHITE_TEXT;
    pokemonSortMenu(pokemonCatalogue, direction);
    std::cout << RESET_TEXT;

    return 0;

}


std::set<std::string> chooseFiles(std::set<std::string>& filesToRead, std::string instruction){ //instruction has already been initialised to an invalid value

    while (instruction != "c"){

        if (instruction == "a"){
            fillAll(filesToRead);

            return filesToRead;
        } else if (instruction >= "1" && instruction <= "9") {
            std::string fileName = "Pokemon" + instruction + ".txt";
            filesToRead.insert(fileName);
        } else if (instruction == "e") {
                exit(0);
        }

        std::cout << "Enter a generation number 1-9, a to add all files, c to continue, or e to exit the program: ";
        std::cin >> instruction;

    }

    return filesToRead;
}

void fillAll(std::set<std::string>& fileToRead){

    std::string fileName = "file";
    for (int i = 1; i < 10; i ++){
        fileName = "Pokemon" + std::to_string(i) + ".txt";

        fileToRead.insert(fileName);
    }

}

void pokemonSortMenu(const Catalogue& catalogue, std::string instruction){

    while (instruction != "e") {

            if (instruction == "g"){ //list Pokémon by numerical order
                std::cout << catalogue;}
            else if (instruction == "a") {//sort Pokemon alphabetically by name
                catalogue.sortAlpha();}
            else if (instruction == "t"){ //see all Pokemon of a type, or organise by type
                std::cout << "Enter a type of pokemon to sort by: ";
                std::string type;
                std::cin >> type;
                catalogue.sortType(type);}
            else if (instruction == "e"){
                exit(0);}

            std::cout << "Enter g to sort by generation, t to sort by type, and a to sort alphabetically, and e to exit: ";
            std::cin >> instruction;


         }

    }
