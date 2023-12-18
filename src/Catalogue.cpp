#include "../include/Catalogue.h"
#include <iostream>
#include <fstream>


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

void Catalogue::fillCatalogue(const std::set<std::string>& generationFiles){

    for (const std::string& file: generationFiles) {
        std::ifstream infile(file);
        readGen(infile);
    }
}

void Catalogue::readGen(std::istream& ins){
    while (ins){

        Pokemon pokemon;
        ins >> pokemon;
        allPokemon.push_back(pokemon);
    }

}
void Catalogue::display(std::ostream& outs) const {

    for (const Pokemon& monster: *this){
        outs << monster;
    }

}

void Catalogue::sortAlpha() const
{
    //use copy constructor
    Catalogue toSort(*this);
    //sort the copied version
    //call display function
    //std::cout << toSort;
}


void Catalogue::sortType() const
{

    //use copy constructor
    //sort copied version
    //call display function
}
