/**
 * Project Untitled
 */


#ifndef _Rat_H
#define _Rat_H

#include "Herbivore.h"
#include "SimulationController.h"


class Rat: public Herbivore {
    public:
    Rat(SimulationController *, int, int);
    virtual Creature * getInstance();
};

#endif //_Rat_H