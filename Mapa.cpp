#include "Mapa.h"
#include "Obiekt_mov.h"

#include <iostream>

using namespace std;

Mapa::Mapa(int wysokosc, int szerokosc)
{
	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
	//this->liczba_bot = liczba_bot;
}

void Mapa::map_generator(Obiekt_mov p[6])
{
	int control = 1;

	for (int x = 0; x <= wysokosc; x++)				// os x (pionowa)
	{
		for (int y = 0; y <= szerokosc; y++)		// os y	(pozioma)
		{
			for (int i = 0; i < 6; i++)
			{
				if ((((x + 1) == p[i].pos_x) && ((y + 1) == p[i].pos_y)) || ((x == p[i].pos_x) && ((y + 1) == p[i].pos_y)) || (((x - 1) == p[i].pos_x) && ((y + 1) == p[i].pos_y)))		// chck pozycja
				{
					if (p[i].direction == 1)					// check kierunek W
					{
						if ((x + 1) == p[i].pos_x)
						{
							std::cout << "  xx  ";

						}
						else if ((x == p[i].pos_x))
						{
							std::cout << "xxooxx";

						}
						else if (((x - 1) == p[i].pos_x))
						{
							std::cout << "xx  xx";

						}
						y += 2;
					}
					else if (p[i].direction == 3)					// check kierunek S
					{
						if ((x + 1) == p[i].pos_x)
						{
							std::cout << "xx  xx";

						}
						else if ((x == p[i].pos_x))
						{
							std::cout << "xxooxx";
						}
						else if (((x - 1) == p[i].pos_x))
						{
							std::cout << "  xx  ";

						}
						y += 2;
					}
					else if (p[i].direction == 2)					// check kierunek A
					{
						if ((x + 1) == p[i].pos_x)
						{
							std::cout << "  xxxx";

						}
						else if ((x == p[i].pos_x))
						{
							std::cout << "xxoo  ";

						}
						else if (((x - 1) == p[i].pos_x))
						{
							std::cout << "  xxxx";

						}
						y += 2;
					}
					else if (p[i].direction == 4)					// check kierunek D
					{
						if ((x + 1) == p[i].pos_x)
						{
							std::cout << "xxxx  ";

						}
						else if ((x == p[i].pos_x))
						{
							std::cout << "  ooxx";

						}
						else if (((x - 1) == p[i].pos_x))
						{
							std::cout << "xxxx  ";

						}
						y += 2;
					}
					control = 0;
				}

			}
			if ((x == 0) || (x == wysokosc) || (y == 0) || (y == szerokosc))
			{
				std::cout << "xx";
				control = 0;
			}
			else if (control == 1)
			{
				std::cout << "  ";
			}
			control = 1;
				
		}
		std::cout << "\n";
	 }
}