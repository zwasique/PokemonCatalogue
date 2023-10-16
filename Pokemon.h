#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>


using namespace std::rel_ops; //not sure if we'll need this

class Pokemon{

private:
    std::string name;
    int number;
    std::string type;
    bool Starter;

    /*i think we would have this regardless of
    * if it's a legendary or not */
    bool Legendary;

    /*i figured it would be cool if whenever someone outputs
     * a whole Pokémon, they could see a fact or two */
    std::vector<std::string> trivia;
public:
    // Default to false for all bools, blank type, number 0
    Pokemon();

    // i figured we'd be reading Pokémon from a file so..?
    Pokemon(std::string name, int num,
            std::string type, bool starter, bool legendary);

    std::string getName() const;

    int getNumber() const;

    bool isLegendary() const;

    bool isStarter() const;

    std::string getType() const;


    void display(std::ostream &outs) const;

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

#endif