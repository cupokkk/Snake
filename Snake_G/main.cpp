#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include <string>
#include <string.h>
#include "Snake.h"
#include "Food.h"
using namespace sf;
/*
Обозначения карты:
0 - пусто
1 - змейка
2 - еда
*/


int map[WIDTH / ELEM_SIZE][HEIGHT / ELEM_SIZE] = { { 0 } };
int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(WIDTH + ADDITIONAL_WIDTH, HEIGHT, 32), "Snake Game",
		Style::Titlebar | Style::Close);

	window.setVerticalSyncEnabled(true);

	Event event;

	/*Еда на рандомной позиции*/
	Food foodMng;
	foodMng.generateFood(WIDTH / ELEM_SIZE, HEIGHT / ELEM_SIZE);

	/*Змейка*/
	Snake snake(5, 5, LEVEL_SPEED[0], RIGHT);
	snake.setDirection(RIGHT);
	

	/*Определения прямоугольников для рисования*/
	RectangleShape test;
	test.setSize(Vector2f(ELEM_SIZE, ELEM_SIZE));

	RectangleShape food;
	food.setSize(Vector2f(ELEM_SIZE, ELEM_SIZE));
	food.setFillColor(Color::Green);


	/*Граница экрана, находиться справа*/
	RectangleShape right_line;
	right_line.setSize(Vector2f(1, 1));
	right_line.setFillColor(Color::Red);

	/* Текст. Можно написать покомпактнее. */
	Text text_snake_length;
	Font font;
	font.loadFromFile("ArialItalic.ttf");
	text_snake_length.setFont(font);
	text_snake_length.setPosition(WIDTH + ELEM_SIZE, ELEM_SIZE);
	text_snake_length.setCharacterSize(TEXT_SIZE);
	text_snake_length.setColor(Color::White);


	while (window.isOpen())
	{
		window.setFramerateLimit(snake.getSpeed());
/////////////////// Control
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			snake.addElement();
			
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (snake.getDirection() != RIGHT)
				snake.setDirection(LEFT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (snake.getDirection() != LEFT)
				snake.setDirection(RIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{

			if (snake.getDirection() != DOWN)
				snake.setDirection(UP);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (snake.getDirection() != UP)
				snake.setDirection(DOWN);
		}

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
/////////////////////////

		memset(map, 0, sizeof(map[0][0]) * WIDTH / ELEM_SIZE * HEIGHT / ELEM_SIZE);

		snake.update();
		foodMng.update();
		snake.move();
		
		for (int j = 0; j < 48; j++)
		{
			for (int i = 0; i < 64; i++)
			{
				if (map[i][j] == 1)
				{
					test.setPosition(i*ELEM_SIZE, j*ELEM_SIZE);
					food.setPosition(foodMng.getPosition().x, foodMng.getPosition().y);
					window.draw(test);
				}
				else if (map[i][j] == 2)
				{
					food.setPosition(foodMng.getPosition().x * ELEM_SIZE, foodMng.getPosition().y * ELEM_SIZE);
					window.draw(food);
				}
				right_line.setPosition(WIDTH, j*ELEM_SIZE);
				window.draw(right_line);
			}
		}


		text_snake_length.setString("Lenght: " + std::to_string(snake.getLength()));
		window.draw(text_snake_length);
		
		window.display();
		window.clear();
	}
	return 0;
}