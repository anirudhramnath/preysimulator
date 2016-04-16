/**
 * Project Untitled
 */


#ifndef _ANIMAL_H
#define _ANIMAL_H

#include "Creature.h"


class Animal: public Creature {
protected: 
    static const float reproduction_probability;
    static const int max_age;
    static const int evading_treshold;
    int age;
    int is_alive;
    

public: 
    Animal(SimulationController *, int, int);
    void move();
    
    /**
     * @param food_level
     */
    
    void growOld();
    
    void reproduce();

    int getHunted();

    void getFood();
    
    void die();

    void setPosition(int, int);

    int getConsumed(int);
};

#endif //_ANIMAL_H