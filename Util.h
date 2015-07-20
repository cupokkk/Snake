#ifndef _UTIL_H_
#define _UTIL_H_

enum direction { UP, DOWN, RIGHT, LEFT };

struct position
{
	int x;
	int y;
	position(){}
};
struct element
{
	position pos;
	element *next;
	element *prev;
	element(){ }
};

#endif