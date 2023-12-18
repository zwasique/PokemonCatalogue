#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>


//using namespace std::rel_ops; not sure if we'll need this

class Pokemon{

private:
    std::string name;
    int number;
    int gen;
    std::string type;


    //std::string specialTag;

    //std::vector<Pokemon> evolutions;



public:
    //  "None" name, number 0, generation 0, "None" type
    Pokemon();


    Pokemon(const std::string& nameIn, int numIn, int genIn, std::string typeIn);

    ~Pokemon();

    std::string getName() const;
    int getNumber() const;
    int getGen() const;
    std::string getType() const;
    //std::string getSpecialTag() const;


    void display(std::ostream &outs) const;

    bool operator==(const Pokemon& otherPokemon) const;

    void read(std::istream& ins);

};

inline
std::ostream& operator<<(std::ostream &outs, const Pokemon &monster)
{
    monster.display(outs);
    return outs;
}

inline
std::istream& operator>>(std::istream& ins, Pokemon pokemon){
    pokemon.read(ins);
    return ins;
}



#endif
