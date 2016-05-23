// Eli Simmonds
// CS315 Lab05
// worm.cpp

#include "worm.hpp"

Worm::Worm( int size ) {
	_size = size;
	_head = _tail = 0;
	_wormArray = new Cell[size];
}

Worm::~Worm() {
	delete [] _wormArray;
}

void Worm::insertHead( Cell c ) {
	_wormArray[_head] = c;
	_head = (_head + 1) % _size;
}


Cell Worm::removeTail() {
// if snake is growing then remove 1 length of tail
// if snake is not growing do not remove. it will look like it is growing. 
	Cell cell = _wormArray[_tail];
	_tail = (_tail + 1) % _size;
	return cell;
}

