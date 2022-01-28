#include <SFML/Graphics.hpp>
#include "const.h"
#include "ball.h"
#include "bat.h"
#include "left_bat.h"
#include "right_bat.h"
#include "text_obj.h"

using namespace sf;
int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(
		VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), 
		"ITSteps SFML Pong"
	);
	window.setFramerateLimit(FPS);
	//�������� ������� ��������
	Ball ball;
	LeftBat left_bat(20, SCREEN_HEIGHT/2 - 50);
	RightBat right_bat(SCREEN_WIDTH - 40, SCREEN_HEIGHT / 2 - 50);
	TextObj left_score(SCREEN_WIDTH /5, 20);
	TextObj right_score(4*SCREEN_WIDTH /5, 20);
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
		right_bat.update();
		left_score.update(std::to_string(ball.getLeftScore()));
		right_score.update(std::to_string(ball.getRightScore()));
		//��������� ������������
		//���� ������������� ���� ������������ � ��������������� ����� ����
		if (ball.getHitBox().intersects(left_bat.getHitBox())) {
			ball.reboundHorizontal();
		}
		if (ball.getHitBox().intersects(right_bat.getHitBox())) {
			ball.reboundHorizontal();
		}
		// ��������� ����
		window.clear(Color(60,60,60));
		window.draw(ball.getShape());
		window.draw(left_bat.getShape());
		window.draw(right_bat.getShape());
		window.draw(left_score.getText());
		window.draw(right_score.getText());
		window.display();
	}
	return 0;
}