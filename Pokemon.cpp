#include "Pokemon.h"

Pokemon::Pokemon()
    :Pokemon("Unnamed", 0, "None", false, false)
{

}


std::ostream& operator<<(std::ostream &outs, const Pokemon &monster)
{
    monster.display(outs);
    return outs;

}
void Pokemon::display(std::ostream &outs) const
{
    outs << "Name: " << getName() << "\n"
    << "Number: " << getNumber() << "\n"
    << "Type: " << getType() << "\n"
    << "Starter: " << isStarter() << "\n"
    << "Legendary: " << isLegendary() << "\n";
    //something to out the trivia
}