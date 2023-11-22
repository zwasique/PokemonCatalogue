#include "../include/Pokemon.h"

#include <utility>

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

std::ostream& operator<<(std::ostream &outs, const Pokemon &monster)
{
    monster.display(outs);
    return outs;

}
void Pokemon::display(std::ostream &outs) const
{
    outs << "Name: " << getName() << "\n"
    << "Number: " << getNumber() << "\n"
    << "Type: " << getType() << "\n"
    << "Gen: " << getGen() << "\n"
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


