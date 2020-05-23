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

void hit_check(Pocisk &pocisk, Obiekt_mov &obiekt);    //sprawdza trafienie.

void player_mov(); // ruch gracza

// obiekty

Mapa level_0(45,74);
Obiekt_mov player[9] = { Obiekt_mov(10, 10, 1, 1, 1, 1), Obiekt_mov(15, 20, 2, 1, 1, 1), Obiekt_mov(30, 30, 2, 1, 1, 1), 
                         Obiekt_mov(40, 10, 2, 1, 1, 1), Obiekt_mov(40, 20, 3, 1, 1, 1), Obiekt_mov(40, 30, 4, 1, 1, 1),
                         Obiekt_mov(40, 55, 2, 1, 1, 1), Obiekt_mov(40, 60, 3, 1, 1, 1), Obiekt_mov(40, 70, 4, 1, 1, 1), };

Pocisk pocisk[9] = { Pocisk(5,5,1,1,2,0), Pocisk(5,7,3,1,2,0), Pocisk(5,8,3,1,2,0),
                     Pocisk(5,9,3,1,2,0), Pocisk(5,12,3,1,2,0), Pocisk(5,15,3,1,2,0),
                     Pocisk(5,25,3,1,2,0), Pocisk(5,35,3,1,2,0), Pocisk(5,45,3,1,2,0), };

//Pocisk pocisk[9];

Fizyka kolizja;

int main()
{
    kolizja.set_kolizja();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ The Tanks ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << " Pls use fullscreen :)\n";

    for (int i = 0; i <= 35; i++)
    {
        cout << " . ";
        Sleep(50);
    }

    system("cls");

    while (true)
    {
        player[0].hp_check();
                kolizja.check_kolizja(&player[0]);
        player_mov();
        for (int p = 0; p < 9; p++)
        {
            pocisk[p].new_pos();
        }
        for (int i = 1; i < 9; i++)
        {
            player[i].hp_check();
                kolizja.check_kolizja(&player[0]);
            player[i].ai_module(kolizja.kolizja[i][1], kolizja.kolizja[i][3], kolizja.kolizja[i][2], kolizja.kolizja[i][4], pocisk[i]);
        }

        for (int pc = 0; pc < 9; pc ++)
        {
            for (int ob = 0; ob < 9; ob++)
            {
                if (pc == ob)
                {
                    ob++;
                }
                hit_check(pocisk[pc],player[ob]);
            }
        }

        level_0.map_generator(&player[0], &pocisk[0]);

        Sleep(444);
        system("cls");
    }

    return 0;
}

void hit_check(Pocisk &pocisk, Obiekt_mov &obiekt)
{
    if ((((pocisk.pos_x - 1) == obiekt.pos_x) || ((pocisk.pos_x + 1) == obiekt.pos_x) || (pocisk.pos_x == obiekt.pos_x)) &&
        (((pocisk.pos_y - 1) == obiekt.pos_y) || ((pocisk.pos_y + 1) == obiekt.pos_y) ||  (pocisk.pos_y == obiekt.pos_y)))
    {
        obiekt.hp = 0;
        pocisk.visible = 0;
        pocisk.reload = 0;
    }
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
        case ' ':
        {
            player[0].fire_5(pocisk[0]);
            break;
        }
        }
        while (_kbhit())
        {
            _getche();
        }
    }
}
