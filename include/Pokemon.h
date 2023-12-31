#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>


class Pokemon{

private:
    std::string name;
    int number;
    int gen;
    std::string type;
    std::string evolvedForm;




public:
    //  "None" name, number 0, generation 0, "None" type, "None" evolvedForm
    Pokemon();


    Pokemon(const std::string& nameIn, int numIn, int genIn, std::string typeIn, std::string evolvedToIn);

    ~Pokemon();

    std::string getName() const;
    int getNumber() const;
    int getGen() const;
    std::string getType() const;
    std::string getEvolvedForm() const;

    void display(std::ostream &outs) const;

    bool operator==(const Pokemon& otherPokemon) const;

    void read(std::istream& ins);

};

inline
std::ostream& operator<<(std::ostream &outs, const Pokemon &monster)
{
    //std::cerr << "std::ostream& operator<< (std::ostream &outs, const Pokemon & monster)";
    monster.display(outs);
    return outs;
}

inline
std::istream& operator>>(std::istream& ins, Pokemon& pokemon){
    //std::cerr << "std::istream& operator>> (std::istream& ins, Pokemon pokemon)";
    pokemon.read(ins);
    return ins;
}



#endif
