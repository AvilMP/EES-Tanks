#pragma once

#include <iostream>

using namespace std;

class Obiekt_mov;
class Mapa;

class Pocisk
{
public:

	friend class Mapa;
	friend void hit_check(Pocisk &pocisk, Obiekt_mov &obiekt);
	

public:

	int pos_x, pos_y; // 1, 2
	int direction;	// 3
	int power; // opcjonanie;
	int speed;
	int visible;
	int reload;

public:

	Pocisk(int = 0, int = 0, int = 0, int = 1, int = 1, int = 0, int = 0);

	~Pocisk();

	void new_pos();
};

