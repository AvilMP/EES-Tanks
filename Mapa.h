#pragma once

#include <iostream>

using namespace std;

class Obiekt_mov;
class Pocisk;

class Mapa
{
public:

	friend class Pocisk;

private:

	int wysokosc;	// okna
	int szerokosc;	// okna



public:
	Mapa(int wysokosc, int szerokosc);

	~Mapa() {};

	void map_generator(Obiekt_mov p[9], Pocisk s[9]);
};

