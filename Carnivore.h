/**
 * Project Untitled
 */


#ifndef _CARNIVORE_H
#define _CARNIVORE_H

#include "Animal.h"
#include "Deer.h"


class Carnivore: public Animal {
public: 
    Carnivore(SimulationController * environment, int position_x, int position_y);
    virtual void getFood();
    virtual void move();
    void chase();
    void hunt();
};

#endif //_CARNIVORE_H