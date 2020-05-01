#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "Mapa.h"
#include "Fizyka.h"
#include "Obiekt_mov.h"
#include "Pocisk.h"

using namespace std;

// glowne funkcje;

bool hit_check(Pocisk pocisk, Obiekt_mov obiekt);    //sprawdza trafienie.
void obiect_loader(Mapa mapa, Obiekt_mov obiekt);



// obiekty

Mapa level_0(45,75,6);

int main()
{
    Obiekt_mov player(20, 20, 1, 3, 1, 1);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ The Tanks ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << " Pls use fullscreen :)\n";

    for (int i = 0; i <= 30; i++)
    {
        cout << " . ";
        Sleep(120);
    }

    system("cls");

    char ruch;

    while (true)
    {
        level_0.map_generator(player);
        

        Sleep(720);

        while( _kbhit() != 0)
        { 
            ruch = _getch();

            switch (ruch)
            {
            case 'w':
            {
                player.mov_up_W();



                break;
            }
            case 's':
            {
                player.mov_down_S();
                



                break;
            }
            case 'a':
            {
                player.mov_left_A();



                break;
            }
            case 'd':
            {
                player.mov_right_D();



                break;
            }
            case '5':
            {




             
            }
            case ' ':
            {




                break;
            }
            }
        }

        system("cls");
    }

    return 0;
}

bool hit_check(Pocisk pocisk, Obiekt_mov obiekt)
{
    if (((pocisk.pos_x - 1) == obiekt.pos_x) || ((pocisk.pos_x + 1) == obiekt.pos_x) &&
        ((pocisk.pos_y - 1) == obiekt.pos_y) || ((pocisk.pos_y + 1) == obiekt.pos_y))
    {
        pocisk.~Pocisk();

        return true;
    }
    else return false;
}

void obiect_loader(Mapa mapa, Obiekt_mov obiekt)
{
    cout << "test/git/test";
}
