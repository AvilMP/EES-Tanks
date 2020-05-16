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

	int pos_x, pos_y;	 // 1,2
	int direction;		 // 3
	int hp;				 // 4
	int speed;			 // 5
	int reload;			 // 6
	

public:

	Obiekt_mov(int = 2, int = 2, int = 0, int = 3, int = 1, int = 1);

	~Obiekt_mov();

	void mov_up_W(int kolizja);
	void mov_down_S(int kolizja);
	void mov_left_A(int kolizja);
	void mov_right_D(int kolizja);

	void fire_5(Pocisk &pc);

	void ai_module(int kol_w, int kol_s, int kol_a, int kol_d);
};