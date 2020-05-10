#include "Obiekt_mov.h"
#include "Mapa.h"
#include "Fizyka.h"


#include <iostream>
#include <time.h>


using namespace std;

Obiekt_mov::Obiekt_mov(int posx, int posy, int direct, int hitp, int seed,int reloading)
{
	pos_x     = posx;
	pos_y	  = posy;
	direction = direct;
	hp        = hitp;
	speed     = seed;
	reload    = reloading;
}

Obiekt_mov::~Obiekt_mov()
{

}

void Obiekt_mov::mov_up_W(int kolizja)
{
	if ((pos_x > 2) && (direction == 1) && (kolizja == 0 ))
	{
		pos_x -= 1;
	}
	direction = 1;
}

void Obiekt_mov::mov_down_S()
{
	if (pos_x < 43 && (direction == 3))
	{
		pos_x += 1;
	}
	direction = 3;
}

void Obiekt_mov::mov_left_A()
{
	if (pos_y > 2 && (direction == 2))
	{
		pos_y -= 1;
	}
	direction = 2;
}

void Obiekt_mov::mov_right_D()
{
	if (pos_y < 72 && (direction == 4))
	{
		pos_y += 1;
	}
	direction = 4;
}

void Obiekt_mov::fire_5()
{

}

void Obiekt_mov::ai_module()
{
	srand(time(NULL));

	static int changer = 1;

	int random = 1;
	changer += 1;



	random = rand() % 4 + 1;

	random = (changer + random) % 4 + 1;

	switch (random)
	{
	case 1:
	{
		//mov_up_W();
		break;
	}
	case 2:
	{
		//mov_down_S();
		break;
	}
	case 3:
	{
		//mov_left_A();
		break;
	}
	case 4:
	{
		//mov_right_D();
		break;
	}
	case 5:
	{
		break;
	}
}
}