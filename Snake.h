#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "Util.h"

class Snake
{
public:
	Snake();
	Snake(int x, int y, int speed);
	Snake(const Snake &);
	~Snake();

	void setDirection(direction dir);
	direction getDirection() const { return m_dir; }
	element * getHead() const { return m_head; }
	element * getTailPosition() const { return m_tail; }

	void addElement();
private:
	direction m_dir;
	element * m_head;
	element * m_tail;
	int m_speed;
	int length;
};
#endif