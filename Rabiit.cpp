/**
 * Project Untitled
 */


#include "Rabiit.h"

/**
 * Rabiit implementation
 */
Rabbit::Rabbit(SimulationController * environment, int position_x, int position_y): 
Herbivore(environment, position_x, position_y, 20){

}
Creature * Rabbit::getInstance(){
    Creature * rabbit = new Rabbit(environment, 0, 0);
	return rabbit;
}