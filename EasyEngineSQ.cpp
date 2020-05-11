﻿#include <iostream>
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

void player_mov(); // ruch gracza

// obiekty

Mapa level_0(45,74);
Obiekt_mov player[9] = { Obiekt_mov(10, 10, 1, 1, 1, 1), Obiekt_mov(15, 20, 2, 1, 1, 1), Obiekt_mov(30, 30, 2, 1, 1, 1), 
                         Obiekt_mov(40, 10, 2, 1, 1, 1), Obiekt_mov(40, 20, 3, 1, 1, 1), Obiekt_mov(40, 30, 4, 1, 1, 1),
                         Obiekt_mov(40, 55, 2, 1, 1, 1), Obiekt_mov(40, 60, 3, 1, 1, 1), Obiekt_mov(40, 70, 4, 1, 1, 1), };
Fizyka kolizja;

int main()
{
    kolizja.set_kolizja();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ The Tanks ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << " Pls use fullscreen :)\n";

    for (int i = 0; i <= 30; i++)
    {
        cout << " . ";
        Sleep(80);
    }

    system("cls");


    while (true)
    {
        kolizja.check_kolizja(&player[0]);
        cout << kolizja.kolizja[0][2];
        player_mov();

        for (int i = 2; i < 9; i++)
        {
           player[i].ai_module();
        }

        level_0.map_generator(&player[0]);

        Sleep(400);
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

void player_mov()
{
    char ruch;

    while (_kbhit() != 0)
    {
        ruch = _getch();

        switch (ruch)
        {
        case 'w':
        {
            player[0].mov_up_W(kolizja.kolizja[0][1]);
            break;
        }
        case 's':
        {
            player[0].mov_down_S(kolizja.kolizja[0][3]);
            break;
        }
        case 'a':
        {
            player[0].mov_left_A(kolizja.kolizja[0][2]);
            break;
        }
        case 'd':
        {
            player[0].mov_right_D(kolizja.kolizja[0][4]);
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
        while (_kbhit())
        {
            _getche();
        }
    }
}
