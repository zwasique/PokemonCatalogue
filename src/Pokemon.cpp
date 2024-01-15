#include "../include/Pokemon.h"
#include <utility>
#include <iomanip>
#include <iostream>
#include <string>
#include <fmt/core.h>


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
  // std::cerr << "Void Pokemon::display(std::ostream &outs) const";

     fmt::print("{:4}{:<6}{:6}{:20}{:6}{:<10}{:6}{:44}{:10}{:20}\n","Gen: ",  getGen(), "Name: ", getName(), "Num: ", getNumber(), "Type: ", getType(),"Evolved Form: ",  getEvolvedForm());

//	fmt::print("{:10}\n","Gen: ",  getGen(), "Name: ","{:20}",  getName(), "Num: ","{:6}",  getNumber(), "Type: ", "{:20}", getType(),"Evolved Form: ", "{:20}",  getEvolvedForm());
}

void Pokemon::read(std::istream& ins) {

        //std::cerr << "void Pokemon::read(std::istream & ins)";
     std::string numberString, genString;

     std::getline(ins, this->name, ';');


     std::getline(ins, numberString, ';');

     try {
         this->number = std::stoi(numberString, nullptr, 10);
     } catch (std::exception &err) {
  //     std::cerr << "Failed Conversion\n";
     }


     std::getline(ins, genString, ';');

     try {
         this->gen = std::stoi(genString, nullptr, 10);
     } catch (std::exception &err) {
//       std::cerr << "Failed Conversion\n";
     }

     std::getline(ins, this->type, ';');

     std::getline(ins, this->evolvedForm, ';');

	ins.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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



