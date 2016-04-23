/**
 * Project Untitled
 */
#include <iostream>


#include "Animal.h"
#include "SimulationController.h"
#include "Rabiit.h"

/**
 * Animal implementation
 */

Animal::Animal(SimulationController * environment, int position_x, int position_y, int min_food):
Creature(environment, position_x, position_y, min_food){
	age = 0;
	is_alive = 1;
}



/**
 * @param food_level
 */


int Animal::getConsumed(int temp){
	cout<<"current foodlevel of the hunted animal"<<current_food_level<<"\n";
	if(current_food_level < evading_treshold) {
		die();
		return current_food_level;
	}
	else
		return 0;
}

void Animal::growOld() {
	age+=1;
    if(age == max_age){
    	die();
    }
}


void Animal::reproduce() {
	/*
	if(current_food_level> max_food_level * reproduction_treshold/(float)100){
		environment->addChild(getInstance(), position_x, position_y);
	}
	*/
	environment->addChild(getInstance(), position_x, position_y);
}




void Animal::setPosition(int position_x, int position_y){
	cout<<"set position tried for"<<position_x<<","<<position_y<<"\n";
	environment->changePosition(this, position_x, position_y);
	Creature::position_x = position_x;
	Creature::position_y = position_y;
}

void Animal::metabolize(){
	Creature::metabolize();
	growOld();
	if(current_food_level == 0){
		die();
	}
}
void Animal::die() {
	cout<<"inside die method *******"<<endl;
	environment->removeCreature(this);
	is_alive = 0;
}
void Animal::routine(){
	if (is_alive != 0) { 
	move();
	getFood();
	reproduce();
	metabolize();
}
}
