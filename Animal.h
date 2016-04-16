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

    virtual void getFood()=0;

    virtual Creature * getInstance()=0;
    
    void die();

    void setPosition(int, int);

    int getConsumed(int);
};

#endif //_ANIMAL_H