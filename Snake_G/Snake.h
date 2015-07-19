#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "Util.h"
#include <vector>
#include <list>
class Snake
{
public:
	Snake();
	Snake(int x, int y, int speed, direction dir);
	Snake(const Snake &);
	~Snake();

	void setDirection(direction dir);
	direction getDirection() const { return m_dir; }
	int getLength() const { return m_length; }
	int getSpeed() const { return m_speed; }
	int colission(int x, int y);
	void move();
	void addElement();
	void update();
private:
	direction m_dir;
	int m_speed;
	int m_length;
	int m_level;
	std::list<element> snake;
};
#endif