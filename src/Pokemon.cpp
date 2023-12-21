#include "../include/Pokemon.h"

#include <utility>
#include <iomanip>
#include <iostream>
#include <string>


Pokemon::Pokemon()
    :Pokemon("None", 0, 0, "None", "None")
{

}

Pokemon::Pokemon(const std::string& nameIn, int numIn, int genIn, std::string typeIn, std::string evolvedToIn) {
    this->name = nameIn;
    this->number = numIn;
    this->gen = genIn;
    this->type = std::move(typeIn);
    this->evolvedForm = std::move(evolvedToIn);

}

Pokemon::~Pokemon() = default;

bool Pokemon::operator==(const Pokemon& otherPokemon) const
{
    return (this->number == otherPokemon.number)
        && (this->gen == otherPokemon.gen);
}


void Pokemon::display(std::ostream &outs) const
{
    //std::cerr << "Void Pokemon::display(std::ostream &outs) const";

    outs << std::left << "Gen: " << std::setw(8) << getGen() << "Name: " << std::setw(20) << getName()
        << "Number: " << std::setw(8) << getNumber() << "Type: " << std::setw(20) << getType() << "Evolved Form: "
        << getEvolvedForm() << "\n";

}

void Pokemon::read(std::istream& ins) {

        //std::cerr << "void Pokemon::read(std::istream & ins)";
        std::string numberString, genString;

        std::getline(ins, this->name, ';');

        std::getline(ins, numberString, ';');
        std::string::iterator end_pos = std::remove(numberString.begin(), numberString.end(), ' ');
        numberString.erase(end_pos, numberString.end());
        try {
            this->number = std::stoi(numberString, nullptr, 10);
        } catch (std::exception &err) {
            std::cerr << "bruh";
        }

        std::getline(ins, genString, ';');
        std::string::iterator end_posi = std::remove(genString.begin(), genString.end(), ' ');
        genString.erase(end_posi, genString.end());
        try {
            this->gen = std::stoi(genString, nullptr, 10);
        } catch (std::exception &err) {
            std::cerr << "bruh";
        }

        std::getline(ins, this->type, ';');

        std::getline(ins, this->evolvedForm, ';');

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

std::string Pokemon::getEvolvedForm() const
{
    return this-> evolvedForm;
}



