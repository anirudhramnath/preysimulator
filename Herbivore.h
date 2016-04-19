/**
 * Project Untitled
 */


#ifndef _HERBIVORE_H
#define _HERBIVORE_H
#include <math.h>
#include "Creature.h"
#include "Animal.h"
#include "Grass.h"


class Herbivore: public Animal {
public: 
    Herbivore(SimulationController *, int, int, int);
    virtual void getFood();
    virtual void move();
    virtual Creature * getInstance()=0;
    void grace();
};

#endif //_HERBIVORE_H