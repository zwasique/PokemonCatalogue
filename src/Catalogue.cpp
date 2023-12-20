#include "../include/Catalogue.h"
#include <fstream>
#include <filesystem>

namespace fs = std::__fs::filesystem;

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

Catalogue::PokemonCatalogue Catalogue::getAllPokemon() {
    return allPokemon;
}

void Catalogue::fillCatalogue(const std::set<std::string>& generationFiles){
    //std::cerr<< "void Catalogue::fillCatalogue(const std::setMstd::string>& generationFiles)";
    fs::path parentPath = "..";
    fs::path withDirectory = parentPath / "pokemonGenerationFiles";

    for (const std::string& file: generationFiles) {
        fs::path fullPath = withDirectory / file;
        //std::string stringPath = fullPath.string();
        std::ifstream fileStream(fullPath);


        if (fileStream.is_open()){
            readGen(fileStream);
        } else {
            std::cerr << "file not found\n";
        }
    }
}

void Catalogue::readGen(std::istream& ins){
    //std::cerr << "void Catalogue::readGen(std::istream& ins)";

    while (ins){

        Pokemon pokemon;
        ins >> pokemon;
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
    //use copy constructor
    std::cout << "not yet buddy \n";
    //Catalogue toSort(*this);
    //sort the copied version
    //call display function
    //std::cout << toSort;
}


void Catalogue::sortType() const
{
    std::cout << "not yet buddy \n";
    //use copy constructor
    //sort copied version
    //call display function
}
