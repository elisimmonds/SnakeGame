// Eli Simmonds
// CS315 lab05
// freepool.cpp

#ifndef FREEPOOL_H
#define FREEPOOL_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <array>

#include "cell.hpp"

class Freepool {
public:
	Freepool( int rows, int cols );
	~Freepool();
	void populate();
	void print();
	void insert( Cell cell );
	void remove( int v );
	Cell atIDX( int v );
	Cell getMunchiePosition();

	int numRows()	{ return _rows; }
	int numCols()	{ return _cols; }
	int lastIndex()	{ return _lastIndex; }
	int size()	{ return _rows * _cols; }

	Cell *listOfFreepool();

private:
	int _rows, _cols, _lastIndex;
	Cell *_freelist; // what size?
};

#endif
