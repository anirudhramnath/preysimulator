/**
 * Project Untitled
 */


#include "Rabbit.h"

/**
 * Rabiit implementation
 */
Rabbit::Rabbit(SimulationController * environment, int position_x, int position_y): Herbivore(environment, position_x, position_y){

}
Creature * Rabbit::getInstance(){
	return (Creature *) new Rabbit(environment, 0, 0);
}