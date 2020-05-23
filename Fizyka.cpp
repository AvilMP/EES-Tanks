#include "Fizyka.h"
#include "Obiekt_mov.h"

#include <iostream>
#include <math.h>

using namespace std;

void Fizyka::set_kolizja()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			kolizja[i][j] = 0;
		}
	}
}

void Fizyka::check_kolizja(Obiekt_mov pl[9])
{
	int break_point = 0;

	for (int i = 0; i < 9; i++)
	{								
		for (int j = 0; j < 9; j++)		
		{
			if (i == j)
			{
				j++;
			}
			if ( (pl[i].pos_x == (pl[j].pos_x + 3)) && (abs(pl[i].pos_y - pl[j].pos_y) <= 2)  )	//lock w (1);
			{
				kolizja[i][1] = 1;
			}
			else
			{
				kolizja[i][1] = 0;
			}
			///
			if ( (pl[i].pos_x == (pl[j].pos_x - 3)) && (abs(pl[i].pos_y - pl[j].pos_y) <= 2)	)	//lock s (3);
			{
				kolizja[i][3] = 1;
			}
			else
			{
				kolizja[i][3] = 0;
			}
			///
			if ((pl[i].pos_y == (pl[j].pos_y + 3)) && (abs(pl[i].pos_x - pl[j].pos_x) <= 2)		)	//lock a (2);
			{
				kolizja[i][2] = 1;
			}
			else
			{
				kolizja[i][2] = 0;
			}
			///
			if ((pl[i].pos_y == (pl[j].pos_y - 3)) && (abs(pl[i].pos_x - pl[j].pos_x) <= 2))	//lock d (4);
			{
				kolizja[i][4] = 1;
			}
			else
			{
				kolizja[i][4] = 0;
			}


			/// przerwanie wyszukiwania nowych kilizji.
			for (int b = 1; b <= 4; b++)
			{
				if (kolizja[i][b] != 0)
				{
					break_point = 1;
				}
			}
			if (break_point == 1)
			{
				break_point = 0;
				break;
			}
		}
	}
}