#include "Pocisk.h"
#include "Mapa.h"

#include <iostream>


using namespace std;

Pocisk::Pocisk(int posx, int posy, int direct, int pow, int seed, int vis, int rel, int idp)
{
	pos_x     = posx;
	pos_y     = posy;
	direction = direct;
	power     = pow; // opjonalne;
	speed     = seed;
	visible   = vis;
	reload    = rel;
	id		  = idp;
}

Pocisk::~Pocisk()
{

}

void Pocisk::new_pos()
{
	if(visible == 1)
	{
		if ((pos_x <= 1) || (pos_x >= 44) || (pos_y <= 1) || (pos_y >= 73))
		{
			visible = 0;
			reload = 0;
		}
		else
		{
			if (direction == 1)
			{
				pos_x -= speed;
			}
			else if (direction == 3)
			{
				pos_x += speed;
			}
			else if (direction == 2)
			{
				pos_y -= speed;
			}
			else if (direction == 4)
			{
				pos_y += speed;
			}
		}
	}
}