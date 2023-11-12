#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>


//using namespace std::rel_ops; not sure if we'll need this

class Pokemon{

private:
    std::string name;
    int gen;
    int number;
    std::string type;

    std::string specialTag;
    // may or may not be implemented
    //std::vector<std::string> trivia;

    Pokemon* evolutions = nullptr;



public:
    // Default to false for all bools, "Non"" type, number 0, generation 0, "None" special tag
    Pokemon();


    Pokemon(const std::string& nameIn, int numIn, int genIn, std::string typeIn, std::string specialTagIn);

    ~Pokemon();

    std::string getName() const;
    int getNumber() const;
    int getGen() const;
    std::string getType() const;
    std::string getSpecialTag() const;


    void display(std::ostream &outs) const;

    bool operator==(const Pokemon& otherPokemon) const;

};

class Legendary: public Pokemon {

    int stat; /* here for now*/

};

std::ostream& operator<<(std::ostream &outs, const Pokemon &monster);



#endif
