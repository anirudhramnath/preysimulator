#include <typeinfo>
#ifndef _ENVIRONMENT_INTERFACES
#define _ENVIRONMENT_INTERFACES
class Environment{
	vector<Creature *>* getCreaturesIn(type class_type, int position_x, int position_y);
	vector<Creature *>* getCreaturesAround(type class_type, int position_x, int position_y);
	vector<Creature *>* getNearestCreature(type class_type, int position_x, int position_y);
	void changePosition(Creature * creature, int position_x, int position_y);
};
class NotEmpty: public Exception{
};
#endif