#pragma once

#include <iostream>

using namespace std;

class Obiekt_mov;
class Pocisk;

class Mapa
{
public:

	friend class Pocisk;

	friend void obiect_loader(Mapa mapa, Obiekt_mov obiekt);

private:

	int wysokosc;	// okna
	int szerokosc;	// okna

	int liczba_bot;

public:
	Mapa(int wysokosc, int szerokosc, int liczba_bot);

	~Mapa() {};

	void map_generator(Obiekt_mov p);

};

