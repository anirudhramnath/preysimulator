/**
 * Project Untitled
 */


#include "Lion.h"
#include "Rabiit.h"

/**
 * Lion implementation
 */


    
Lion::Lion(SimulationController * environment, int position_x, int position_y):
Carnivore(environment, position_x, position_y, 150){
    min_food_level = 150;
    max_food_level = 300;
    max_age = 25;
    reproduction_age = 10;
    reproduction_food = 200;
    reproduction_probability = 40;
    evading_treshold = 2500;
    rate_of_metabolism = 10;

}
void Lion::move(){
    Carnivore::moveTowards(typeid(Rabbit));
}
Creature * Lion::getInstance(){
    Creature * lion = new Lion(environment, 0, 0);
    return lion;
}