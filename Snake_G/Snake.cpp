#include "Snake.h"
#include <cstring>
#include <algorithm>
extern int map[][HEIGHT/ELEM_SIZE];

Snake::Snake()
{

}
Snake::Snake(int x, int y, int speed, direction dir) //не очень метод, нужно будет переделать. пока так
{
	snake.push_back(element(x, y));
	m_dir = dir;
	m_speed = speed;
	m_length = 1;
	m_level = 1;

	addElement();
	addElement();
	addElement();
	addElement();
}
Snake::~Snake()
{

}
void Snake::setDirection(direction dir)
{
	m_dir = dir;
}

void Snake::addElement()
{
	element temp;
	switch (m_dir)
	{
	case UP: {temp.pos.y = snake.back().pos.y + 1; temp.pos.x = snake.back().pos.x; break; }
	case DOWN: {temp.pos.y = snake.back().pos.y - 1; temp.pos.x = snake.back().pos.x; break; }
	case RIGHT: {temp.pos.x = snake.back().pos.x - 1;  temp.pos.y = snake.back().pos.y; break; }
	case LEFT: {temp.pos.x = snake.back().pos.x + 1; temp.pos.y = snake.back().pos.y; break;  }
	default:break;
	}
	snake.push_back(temp);
	m_length += 1;
	printf("Added element!\n");
}


int Snake::colission(int x, int y)
{
	if (map[x][y] == 1) 
		return 1; 
	else if (map[x][y] == 2) 
		return 2; 
}

void Snake::update()
{
	for (auto iter = snake.begin(); iter != snake.end(); iter++)
	{
		if (iter->pos.x < 0) iter->pos.x += WIDTH / ELEM_SIZE;
		else if (iter->pos.x >= WIDTH / ELEM_SIZE) iter->pos.x -= WIDTH / ELEM_SIZE;
		else if (iter->pos.y < 0) iter->pos.y += HEIGHT / ELEM_SIZE;
		else if (iter->pos.y >= HEIGHT / ELEM_SIZE) iter->pos.y -= HEIGHT / ELEM_SIZE;
		map[iter->pos.x][iter->pos.y] = 1;
	}
}

void Snake::move()
{   
	if (LEVEL_LENGTH[m_level] == m_length)	m_speed = LEVEL_SPEED[m_level++];
	
	element temp;
	temp = snake.front();
	
	switch (m_dir)
	{
		case UP:{
				   temp.pos.y -= 1;
				   break;
		}
		case DOWN:{
					 temp.pos.y += 1;
					 break;
		}
		case RIGHT:{
					  temp.pos.x += 1;	 
					  break;
		}
		case LEFT:{
					 temp.pos.x -= 1;
					 break;
		}
		default:break;
	}

	/*Если колижн со змейкой то выходим*/
	if (colission(temp.pos.x, temp.pos.y) == 1)
	{
		exit(1);
	}
	/*Если колижно с едой, то добавляем к змейке элемент*/
	else if (colission(temp.pos.x, temp.pos.y) == 2)
	{
		addElement();

	}

	snake.push_front(temp);
	snake.pop_back();

}
