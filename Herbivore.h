/**
 * Project Untitled
 */


#ifndef _HERBIVORE_H
#define _HERBIVORE_H

#include "Creature.h"
#include "Animal.h"


class Herbivore: public Creature, public Animal {
public: 
    
    int getConsumed();
    
    void evade();
};

#endif //_HERBIVORE_H