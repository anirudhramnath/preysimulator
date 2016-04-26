/**
 * Project Untitled
 */


#ifndef _Lion_H
#define _Lion_H

#include "Carnivore.h"


class Lion: public Carnivore {
    public:
        Lion(SimulationController *, int, int);
        Creature * getInstance();
        void move();

};

#endif //_Lion_H