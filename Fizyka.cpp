#include "Fizyka.h"
#include "Obiekt_mov.h"

#include <iostream>
#include <math.h>

using namespace std;

void Fizyka::set_kolizja()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			kolizja[i][j] = 0;
		}
	}
}

void Fizyka::check_kolizja(Obiekt_mov pl[9])
{
	cout << pl[0].pos_x;
	cout << pl[1].pos_x;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if ( pl[i].pos_x == (pl[j].pos_x + 3) && (abs(pl[i].pos_y - pl[j].pos_y) <= 2)  )	//lock w (1);
			{
				kolizja[i][1] = 1;
				break;
			}
			else
			{
				kolizja[i][1] = 0;
			}
		}
	}
}