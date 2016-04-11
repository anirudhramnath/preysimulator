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
    static const enum Direction {LEFT, RIGHT, UP, DOWN, NO_MOTION};
    void move();
    
    /**
     * @param food_level
     */
    void grow(int food_count);

    void eat(int food_level);
    
    void age();
    
    void reproduce();

    int getHunted();
    
    void die();
};

#endif //_ANIMAL_H