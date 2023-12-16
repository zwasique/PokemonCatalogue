#ifndef CATALOGUE_H_INCLUDED
#define CATALOGUE_H_INCLUDED

#include <iostream>
#include <list>
#include <set>

#include "Pokemon.h"



class Catalogue {
public:
    using PokemonCatalogue = std::list<Pokemon>;

    using iterator = PokemonCatalogue::iterator;
    using const_iterator = PokemonCatalogue::const_iterator;


private:

    /**
     * All pokemen in this 'catalogue'
     */
    PokemonCatalogue allPokemon;

public:
    Catalogue() = default;


    /**
     * When sorting a catalogue, a copy should be made for sorting
     * and that sorted catalogue will be returned. That way,
     * the original catalogue is unaffected by the sort
     * @param src
     */
    Catalogue(const Catalogue& src) = default;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    void readFiles(std::set<std::string> chosenFiles);

    void display(std::ostream& outs) const;

    void sortAlpha() const;
    void sortType() const;


};

inline
std::ostream& operator<<(std::ostream outs, const Catalogue& catalogue)
{
    catalogue.display(outs);
    return outs;
}

#endif