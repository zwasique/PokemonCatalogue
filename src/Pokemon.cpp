#include "../include/Pokemon.h"

#include <utility>
#include <iomanip>


Pokemon::Pokemon()
    :Pokemon("None", 0, 0, "None", "None")
{

}

Pokemon::Pokemon(const std::string& nameIn, int numIn, int genIn, std::string typeIn, std::string specialTagIn) {
    this->name = nameIn;
    this->number = numIn;
    this->gen = genIn;
    this->type = std::move(typeIn);
    this->specialTag = std::move(specialTagIn);

}

Pokemon::~Pokemon() = default;

bool Pokemon::operator==(const Pokemon& otherPokemon) const
{
    return (this->number == otherPokemon.number)
        && (this->gen == otherPokemon.gen);
}


void Pokemon::display(std::ostream &outs) const
{
    outs << "Name: " << std::setw(15) << getName() << "Number: " << std::setw(4) << getNumber()
         << "Type: " << std::setw(15) << getType() << "Gen: " << std::setw(4) << getGen()
         << "Tag: " << getSpecialTag() << "\n";

}

std::string Pokemon::getName() const
{
    return this-> name;
}

int Pokemon::getNumber() const
{
    return this->number;
}

std::string Pokemon::getType() const
{
    return this-> type;
}


int Pokemon::getGen() const
{
    return this-> gen;
}

std::string Pokemon::getSpecialTag() const
{
    return this->specialTag;
}


