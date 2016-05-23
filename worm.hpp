// Eli Simmonds
// CS315 Lab05
// worm.hpp

#ifndef WORM_H
#define WORM_H

#include <array>
#include <stdlib.h>
#include <iostream>

#include "cell.hpp"

class Worm {
public:
	Worm( int size );
	~Worm();
	void insertHead( Cell c );
	Cell removeTail();

	int size()	{ return _size; }
	
private:
	int _head, _tail, _size;
	Cell *_wormArray;
};

#endif
