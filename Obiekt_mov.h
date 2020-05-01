#pragma once

#include <iostream>

using namespace std;

class Pocisk;

class Obiekt_mov
{
public:

	friend class Mapa;

	friend bool hit_check(Pocisk pocisk, Obiekt_mov obiekt);
	

public:

	int pos_x, pos_y;
	int direction;
	int hp;
	int speed;
	int reload;

public:

	Obiekt_mov(int = 2, int = 2, int = 0, int = 3, int = 1, int = 1);

	~Obiekt_mov();

	void mov_up_W();
	void mov_down_S();
	void mov_left_A();
	void mov_right_D();

	void fire_5();

};