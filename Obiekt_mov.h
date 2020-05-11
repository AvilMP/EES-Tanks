#pragma once

#include <iostream>

using namespace std;

class Pocisk;
class Mapa;
class Fizyka;

class Obiekt_mov
{
public:

	friend class Mapa;
	friend class Fizyka;

	friend bool hit_check(Pocisk pocisk, Obiekt_mov obiekt);
	

private:

	int pos_x, pos_y;
	int direction;
	int hp;
	int speed;
	int reload;
	

public:

	Obiekt_mov(int = 2, int = 2, int = 0, int = 3, int = 1, int = 1);

	~Obiekt_mov();

	void mov_up_W(int kolizja);
	void mov_down_S(int kolizja);
	void mov_left_A(int kolizja);
	void mov_right_D(int kolizja);

	void fire_5();

	void ai_module();
};