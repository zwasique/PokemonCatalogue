#include "../include/Catalogue.h"


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

void Catalogue::display(std::ostream& outs) const {

    for (const Pokemon& monster: *this){
        monster.display(outs);
    }

}

void Catalogue::sortAlpha()
{
    //use copy constructor
    //sort the copied version
    //call display function
}

void Catalogue::sortNum()
{
    //use copy constructor
    //sort copied version
    //call display function

}

void Catalogue::sortType()
{
    //use copy constructor
    //sort copied version
    //call display function
}

std::ostream& operator<<(std::ostream outs, const Catalogue& catalogue){
    catalogue.display(outs);
    return outs;

}
