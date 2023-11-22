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
