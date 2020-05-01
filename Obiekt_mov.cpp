#include "Obiekt_mov.h"

#include <iostream>

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

void Obiekt_mov::mov_up_W()
{
	pos_x -= 1;
	direction = 1;
}

void Obiekt_mov::mov_down_S()
{
	pos_x += 1;
	direction = 3;
}

void Obiekt_mov::mov_left_A()
{
	pos_y -= 1;
	direction = 2;
}

void Obiekt_mov::mov_right_D()
{
	pos_y += 1;
	direction = 4;
}

void Obiekt_mov::fire_5()
{

}