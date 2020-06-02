#include "Obiekt_mov.h"
#include "Mapa.h"
#include "Fizyka.h"
#include "Pocisk.h"

#include <iostream>
#include <time.h>


using namespace std;

Obiekt_mov::Obiekt_mov(int posx, int posy, int direct, int hitp, int seed, int idp)
{
	pos_x     = posx;
	pos_y	  = posy;
	direction = direct;
	hp        = hitp;
	speed     = seed;
	id		  = idp;
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

void Obiekt_mov::mov_down_S(int kolizja)
{
	if (pos_x < 43 && (direction == 3) && (kolizja == 0))
	{
		pos_x += 1;
	}
	direction = 3;
}

void Obiekt_mov::mov_left_A(int kolizja)
{
	if (pos_y > 2 && (direction == 2) && (kolizja == 0))
	{
		pos_y -= 1;
	}
	direction = 2;
}

void Obiekt_mov::mov_right_D(int kolizja)
{
	if (pos_y < 72 && (direction == 4) && (kolizja == 0))
	{
		pos_y += 1;
	}
	direction = 4;
}

void Obiekt_mov::fire_5(Pocisk &pc)
{
	if (pc.reload == 0)
	{
		pc.reload = 1;
		pc.visible = 1;
		if (direction == 1)
		{
			pc.direction = 1;
			pc.pos_x = (pos_x - 1);
			pc.pos_y = pos_y;
		}
		else if (direction == 3)
		{
			pc.direction = 3;
			pc.pos_x = (pos_x + 1);
			pc.pos_y = pos_y;
		}
		else if (direction == 2)
		{
			pc.direction = 2;
			pc.pos_x = pos_x;
			pc.pos_y = (pos_y - 1);
		}
		else if (direction == 4)
		{
			pc.direction = 4;
			pc.pos_x = pos_x;
			pc.pos_y = (pos_y + 1);
		}
	}
}

void Obiekt_mov::hp_check()
{
	if (hp <= 0)
	{
		pos_x = 100000;
		pos_y = 100000;
	}
}

void Obiekt_mov::ai_module(int kol_w, int kol_s, int kol_a, int kol_d, Pocisk &pcx)
{
	srand(time(NULL));

	static int changer = 1;

	int random = 1;
	int shoot = 1;

	changer +=  1;

	random = rand() % 4 + 1;
	shoot = rand() % 100 + 1;

	random = (changer + random) % 4 + 1;

	if (shoot <= 25)
	{
		random ++;
	}

	switch (random)
	{
		case 1:
		{
			mov_up_W(kol_w);
			break;
		}
		case 2:
		{
			mov_down_S(kol_s);
			break;
		}
		case 3:
		{
			mov_left_A(kol_a);
			break;
		}
		case 4:
		{
			mov_right_D(kol_d);
			break;
		}
		case 5:
		{
			fire_5(pcx);
			break;
		}
	}
}