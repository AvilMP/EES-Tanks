#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>


#include "Mapa.h"
#include "Fizyka.h"
#include "Obiekt_mov.h"
#include "Pocisk.h"

// glowne funkcje;

void hit_check(Pocisk &pocisk, Obiekt_mov &obiekt);    //sprawdza trafienie.

void player_mov(); // ruch gracza

// obiekty

Mapa level_0(45,74);        // obiekt(x,y,dir,hp,speed,id);
Obiekt_mov player[9] = { Obiekt_mov(40, 36, 1, 1, 1, 0), Obiekt_mov(5, 10, 2, 1, 1, 1), Obiekt_mov(5, 15, 2, 1, 1, 1), 
                         Obiekt_mov(5, 20, 2, 1, 1, 1), Obiekt_mov(5, 30, 3, 1, 1, 1), Obiekt_mov(5, 40, 4, 1, 1, 1),
                         Obiekt_mov(5, 50, 2, 1, 1, 1), Obiekt_mov(5, 60, 3, 1, 1, 1), Obiekt_mov(5, 70, 4, 1, 1, 1), };

                           // pocisk(x,y,dir,pow,speed,vis,rel,id);
Pocisk pocisk[9] = { Pocisk(100,100,1,1,2,0,0,0), Pocisk(99,99,1,1,2,0,0,1), Pocisk(98,98,1,1,2,0,0,1),
                     Pocisk(97,97,1,1,2,0,0,1), Pocisk(96,96,1,1,2,0,0,1), Pocisk(95,95,1,1,2,0,0,1),
                     Pocisk(94,94,1,1,2,0,0,1), Pocisk(93,93,1,1,2,0,0,1), Pocisk(92,92,1,1,2,0,0,1), };

int points, end_point, win_point;

Fizyka kolizja;

int main()
{
    kolizja.set_kolizja();

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ The Tanks ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    std::cout << " Pls use fullscreen :)\n";

    for (int i = 0; i <= 35; i++)
    {
        std::cout << " . ";
        Sleep(50);
    }

    std::system("cls");

    while (true)
    {
        player[0].hp_check();
                kolizja.check_kolizja(&player[0]);
        player_mov();

        // test

        // test

        for (int p = 0; p < 9; p++)
        {
            pocisk[p].new_pos();
        }
        for (int i = 1; i < 9; i++)
        {
            player[i].hp_check();
            kolizja.check_kolizja(&player[0]);
            player[i].ai_module(kolizja.kolizja[i][1], kolizja.kolizja[i][3], kolizja.kolizja[i][2], kolizja.kolizja[i][4], pocisk[i]);
            for (int pc = 0; pc < 9; pc++)
            {
                for (int ob = 0; ob < 9; ob++)
                {
                    if (pc == ob)
                    {
                        ob++;
                    }
                    hit_check(pocisk[pc], player[ob]);
                }
            }
        }
        level_0.map_generator(&player[0], &pocisk[0]);
        std::cout << "\n Twoje Punkty: " << points;


        Sleep(444);
        std::system("cls");
    }

    if (win_point == 0)
    {
        std::cout << " Przegrales :C \n";
    }
    else
    {
        std::cout << " Wygrales :> \n";
    }


    std::cout << "\n Twoje Punkty: " << points;
    std::cout << " !!! ";

    return 0;
}

void hit_check(Pocisk &pocisk, Obiekt_mov &obiekt)
{
    if ((((pocisk.pos_x - 1) == obiekt.pos_x) || ((pocisk.pos_x + 1) == obiekt.pos_x) || (pocisk.pos_x == obiekt.pos_x)) &&
        (((pocisk.pos_y - 1) == obiekt.pos_y) || ((pocisk.pos_y + 1) == obiekt.pos_y) || (pocisk.pos_y == obiekt.pos_y)))
    {
        pocisk.visible = 0;
        pocisk.reload = 0;

        if (pocisk.id != obiekt.id)
        {
            obiekt.hp -= pocisk.power;
            points++;
        }
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
