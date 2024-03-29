#include "../include/Catalogue.h"
#include <fstream>
#include <filesystem>
#include <algorithm>

#define WHITE_TEXT "\033[0;37m"
#define RESET_TEXT "\033[0m"

namespace fs = std::filesystem;

Catalogue::iterator Catalogue::begin()
{
    return allPokemon.begin();
}
Catalogue::iterator Catalogue::end()
{
    return allPokemon.end();
}
Catalogue::const_iterator Catalogue::begin() const
{
    return allPokemon.begin();
}
Catalogue::const_iterator Catalogue::end() const
{
    return allPokemon.end();
}

Catalogue::PokemonCatalogue Catalogue::getAllPokemon() const {
    return allPokemon;
}

void Catalogue::fillCatalogue(const std::set<std::string>& generationFiles){
    //std::cerr<< "void Catalogue::fillCatalogue(const std::set<std::string>& generationFiles)";
    fs::path  parentPath = "..";
    fs::path  withDirectory = parentPath / "pokemonGenerationFiles";

    for (const std::string& file: generationFiles) {
        fs::path fullPath = withDirectory / file;
        //std::string stringPath = fullPath.string();
        std::ifstream fileStream(fullPath);


        if (fileStream.is_open()){
            readGen(fileStream);
            fileStream.close();
        } else {
            std::cerr << "file not found\n";
        }
    }

}

void Catalogue::readGen(std::istream& ins){
    //std::cerr << "void Catalogue::readGen(std::istream& ins)";
    while (!ins.eof()) {

        Pokemon pokemon;
        ins >> pokemon;
        //std::cout << pokemon;

        if (pokemon.getGen() != 0)
            allPokemon.push_back(pokemon);
    }

}
void Catalogue::display(std::ostream& outs) const {

    //std::cerr << "void Catalogue::display(std::ostream& outs) const";
    for (const auto & it : allPokemon){
        outs << it;
    }
}

void Catalogue::sortAlpha() const
{
        std::cout << RESET_TEXT <<  "----------------------------\n" << WHITE_TEXT;
    Catalogue toSort(*this);
    std::sort(toSort.begin(), toSort.end(), [] (Pokemon& one, Pokemon& two){
           return one.getName() < two.getName();});
    std::cout << toSort;
        std::cout << RESET_TEXT <<  "----------------------------\n" << WHITE_TEXT;
}


void Catalogue::sortType(const std::string& type) const
{
	std::cout << RESET_TEXT <<  "----------------------------\n" << WHITE_TEXT;
	Catalogue toSort;

    for (const Pokemon &monster: this->getAllPokemon()) {
        int pos = monster.getType().find(type);
        if (pos < monster.getType().length())
            toSort.allPokemon.push_back(monster);
    }

	std::cout << toSort;
        std::cout << RESET_TEXT <<  "----------------------------\n" << WHITE_TEXT;
}
