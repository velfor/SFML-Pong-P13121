#include <SFML/Graphics.hpp>
#include "const.h"
#include "ball.h"
#include "bat.h"
//#include "left_bat.h"

using namespace sf;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(FPS);
	//Создание игровых объектов
	Ball ball;
	Bat left_bat(20, SCREEN_HEIGHT/2 - 50);
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//2 update
		ball.update();
		left_bat.update();
		// Отрисовка окна
		window.clear(Color(60,60,60,0));
		window.draw(ball.getShape());
		window.draw(left_bat.getShape());
		window.display();
	}
	return 0;
}