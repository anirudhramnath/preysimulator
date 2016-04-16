/**
 * Project Untitled
 */


#ifndef _HERBIVORE_H
#define _HERBIVORE_H

#include "Creature.h"
#include "Animal.h"


class Herbivore: public Animal {
public: 
    Herbivore::Herbivore(SimulationController *, int, int);
    int currentAppetite();

    void grace();
};

#endif //_HERBIVORE_H