#ifndef _UTIL_H_
#define _UTIL_H_

enum direction { UP, DOWN, RIGHT, LEFT };


static const int ELEM_SIZE = 20;
static const int WIDTH = 640;
static const int ADDITIONAL_WIDTH = 150; //для панельки аля длинна, скорость и тд
static const int HEIGHT = 480;

static const int TEXT_SIZE = 20;

/* можешь перенести (переделать) куда хо (как хо). Смысл такой: если*/
static const int LEVEL_SPEED[] = { 15, 18, 22, 25, 30, 35 };
static const int LEVEL_LENGTH[] = { 15, 25, 40, 60, 70, 90 };

struct position
{
	int x;
	int y;
	position(){}
};
struct element
{
	position pos;
	element(int x, int y){ pos.x = x; pos.y = y; }
	element(){}

};

#endif