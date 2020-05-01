#include "Pocisk.h"

#include <iostream>

using namespace std;

Pocisk::Pocisk(int posx, int posy, int direct, int pow, int seed)
{
	pos_x = posx;
	pos_y = posy;
	direction = direct;
	power = pow; // opjonalne;
	speed = seed;
}

Pocisk::~Pocisk()
{

}

void Pocisk::new_pos()
{
	cout << "Test";
}