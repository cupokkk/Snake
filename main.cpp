#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "Snake.h"
#include "Food.h"
using namespace sf;

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(640, 480, 32), "Snake Game",
		Style::Titlebar | Style::Close);
	window.setVerticalSyncEnabled(true);
	Event event;
	Food food;
	Clock clock;
	RectangleShape test;
	test.setSize(Vector2f(5, 5));
	food.setRandomPosition();
	while (window.isOpen())
	{
		Time time = clock.getElapsedTime();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			food.setRandomPosition();
		}
		//window.clear();
		test.setPosition(float(food.getPosition().x), float(food.getPosition().y));
		window.draw(test);
		window.display();
	}
	return 0;
}