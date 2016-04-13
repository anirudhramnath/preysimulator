/**
 * Project Untitled
 */


#ifndef _HERBIVORE_H
#define _HERBIVORE_H

#include "Creature.h"
#include "Animal.h"


class Herbivore: public Animal {
public: 
    
    int getConsumed();
    
    int currentAppetite();

    void evade();
};

#endif //_HERBIVORE_H