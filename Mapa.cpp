#include "Mapa.h"
#include "Obiekt_mov.h"

#include <iostream>

using namespace std;

Mapa::Mapa(int wysokosc, int szerokosc, int liczba_bot)
{
	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
	//this->liczba_bot = liczba_bot;
}

void Mapa::map_generator(Obiekt_mov p[6])
{
	for (int x = 0; x <= wysokosc; x++)				// os x (pionowa)
	{
		for (int y = 0; y <= szerokosc; y++)		//os y	(pozioma)
		{
			for (int i = 0; i < 6; i++ )
			{
				if ((((x - 1) == p[i].pos_x) && (y == p[i].pos_y)) || ((x == p[i].pos_x) && (y == p[i].pos_y)) || (((x + 1) == p[i].pos_x) && (y == p[i].pos_y)))		// chck pozycja
				{
					if (p[i].direction == 1)					// check kierunek W
					{
						if ((x + 1) == p[i].pos_x)
						{
							cout << "  xx  ";
							y += 3;
						}
						else if ((x == p[i].pos_x))
						{
							cout << "xxooxx";
							y += 3;
						}
						else if (((x - 1) == p[i].pos_x))
						{
							cout << "xx  xx";
							y += 3;
						}
					}
					else if (p[i].direction == 3)					// check kierunek S
					{
						if ((x + 1) == p[i].pos_x)
						{
							cout << "xx  xx";
							y += 3;
						}
						else if ((x == p[i].pos_x))
						{
							cout << "xxooxx";
							y += 3;
						}
						else if (((x - 1) == p[i].pos_x))
						{
							cout << "  xx  ";
							y += 3;
						}
					}
					else if (p[i].direction == 2)					// check kierunek A
					{
						if ((x + 1) == p[i].pos_x)
						{
							cout << "  xxxx";
							y += 3;
						}
						else if ((x == p[i].pos_x))
						{
							cout << "xxoo  ";
							y += 3;
						}
						else if (((x - 1) == p[i].pos_x))
						{
							cout << "  xxxx";
							y += 3;
						}
					}
					else if (p[i].direction == 4)					// check kierunek D
					{
						if ((x + 1) == p[i].pos_x)
						{
							cout << "xxxx  ";
							y += 3;
						}
						else if ((x == p[i].pos_x))
						{
							cout << "  ooxx";
							y += 3;
						}
						else if (((x - 1) == p[i].pos_x))
						{
							cout << "xxxx  ";
							y += 3;
						}
					}
				}
			}
			if((x==0)||(x==wysokosc)||(y==0)||(y==szerokosc))
			{
				cout << "xx";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << "\n";
	 }
}