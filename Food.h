#ifndef _FOOD_H_
#define _FOOD_H_
#include "Util.h"
#include <random>
#include <time.h>
extern int map[][HEIGHT / ELEM_SIZE];
class Food
{
public:
	Food() {}
	void generateFood(int width, int height)
	{
		srand(time(NULL));
		m_pos.x = rand() % width;
		m_pos.y = rand() % height;
	}
	position getPosition() const { return m_pos; }
	void update()
	{
		if (map[m_pos.x][m_pos.y] == 1)
			generateFood(WIDTH / ELEM_SIZE, HEIGHT / ELEM_SIZE);
		else
			map[m_pos.x][m_pos.y] = 2;
	}
private:
	Food(const Food &);

	position m_pos;
};
#endif