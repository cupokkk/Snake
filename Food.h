#ifndef _FOOD_H_
#define _FOOD_H_

#include "Util.h"
class Food
{
public:
	Food();
	Food(int x, int y);
	Food(const position &);
	Food(const Food &);
	~Food();

	position getPosition() const;
	void setRandomPosition();
	void setPosition(int x, int y);
private:
	position m_position;
};

#endif