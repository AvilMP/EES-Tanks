#pragma once

#include <iostream>

using namespace std;

class Obiekt_mov;
class Mapa;

class Pocisk
{
public:

	friend class Mapa;
	friend bool hit_check(Pocisk pocisk, Obiekt_mov obiekt);
	

private:

	int pos_x, pos_y;
	int direction;
	int power; // opcjonanie;
	int speed;

public:

	Pocisk(int = 0, int = 0, int = 0, int = 1, int = 2);

	~Pocisk();

	void new_pos();

};

