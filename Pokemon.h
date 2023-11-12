#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>


//using namespace std::rel_ops; //not sure if we'll need this

class Pokemon{

private:
    std::string name;
    int gen;
    int number;
    std::string type;

    std::string specialTag;
    /*i figured it would be cool if whenever someone outputs
     * a whole Pokémon, they could see a fact or two */
    //std::vector<std::string> trivia;

    Pokemon* evolutions = nullptr;



public:
    // Default to false for all bools, blank type, number 0, generation 0
    Pokemon();


    Pokemon(const std::string& name, int num, int gen, std::string type, std::string specialTag);

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

    int stat; /*i don't know enough about legendaries except
    // for the fact that they have added abilities so this is just
    here for now shrug */

};

//Print one Pokémon by invoking display
std::ostream& operator<<(std::ostream &outs, const Pokemon &monster);

inline
std::string Pokemon::getName() const
{
    return this-> name;
}

inline
int Pokemon::getNumber() const
{
    return this->number;
}

inline
std::string Pokemon::getType() const
{
    return this-> type;
}


inline
int Pokemon::getGen() const
{
    return this-> gen;
}

inline
std::string Pokemon::getSpecialTag() const
{
    return this->specialTag;
}

#endif
