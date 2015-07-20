#include "Food.h"
#include <random>
#include <ctime>
Food::Food()
{
	setPosition(0, 0);
}
Food::Food(int x, int y)
{

}
Food::Food(const position &)
{

}
Food::Food(const Food &)
{

}
Food::~Food()
{

}

position Food::getPosition() const
{
	return m_position;
}
void Food::setRandomPosition()
{
	
	m_position.x = rand() % 640;
	m_position.y = rand() % 480;
}
void Food::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}