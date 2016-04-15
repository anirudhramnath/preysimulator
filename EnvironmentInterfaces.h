#include <typeinfo>
#ifndef _ENVIRONMENT_INTERFACES
#define _ENVIRONMENT_INTERFACES


class Environment {
	virtual vector<Creature *>* getCreaturesIn(std::string, int position_x, int position_y) = 0;
	virtual vector<Creature *>* getCreaturesAround(std::string, int position_x, int position_y) = 0;
	virtual vector<Creature *>* getNearestCreature(std::string, int position_x, int position_y) = 0;
	virtual void changePosition(Creature * creature, int position_x, int position_y) = 0;
	virtual void addChild(Creature * child, int position_x, int position_y) = 0;
};
class NotEmpty: public exception{
};
#endif