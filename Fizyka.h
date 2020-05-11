#pragma once

#include <iostream>

using namespace std;

class Obiekt_mov;

class Fizyka
{
public:

	int kolizja[9][5];

private:

public:

	void set_kolizja();

	void check_kolizja(Obiekt_mov pl[9]);
};

