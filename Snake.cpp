#include "Snake.h"

Snake::Snake()
{
	m_head = new element();
	m_head->pos.x = 1;
	m_head->pos.y = 0;
	m_head->next = nullptr;
	m_head->prev = nullptr;
	m_speed = 2;
	length = 1;
}
Snake::Snake(int x, int y, int speed)
{
	m_head = new element();
	m_head->pos.x = x;
	m_head->pos.y = y;
	m_head->next = nullptr;
	m_head->prev = nullptr;
	m_speed = speed;
	length = 1;
}
Snake::~Snake()
{
	while (length > 0)
	{
		m_tail = m_head->next;
		delete m_head;
		m_head = m_tail;
		length--;
	}
}
void Snake::setDirection(direction dir)
{
	m_dir = dir;
}

void Snake::addElement()
{
	element * temp = new element;
	temp->prev = nullptr;
	m_head->prev = temp;
	if (m_tail == nullptr)
	{
		m_tail = new element;
		m_tail = m_head;
	}
	m_head = temp;
	length++;
}