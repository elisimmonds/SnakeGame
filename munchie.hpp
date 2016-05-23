// Eli Simmonds
// CS315 lab05
// munchie.hpp

#ifndef MUNCHIE_H
#define MUNCHIE_H

#include <iostream>
#include <stdlib.h>
#include <string>

#include "cell.hpp"

class Munchie {
public:
	Munchie ( Cell cell ); // do i need size?
	~Munchie();
	int row();
	int column();
	int size();
	
private:
	int _row;
	int _col;
	int _size; // possibly dont need
};

#endif

