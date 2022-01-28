#include <SFML/Graphics.hpp>
#include "const.h"
#include "ball.h"
#include "bat.h"
//#include "left_bat.h"

using namespace sf;
int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(FPS);
	//�������� ������� ��������
	Ball ball;
	Bat left_bat(20, SCREEN_HEIGHT/2 - 50);
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//2 update
		ball.update();
		left_bat.update();
		// ��������� ����
		window.clear(Color(60,60,60,0));
		window.draw(ball.getShape());
		window.draw(left_bat.getShape());
		window.display();
	}
	return 0;
}