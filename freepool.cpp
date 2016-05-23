// Eli Simmonds
// CS315 Lab 05
// freepool.cpp

#include "freepool.hpp"

Freepool::Freepool( int rows, int cols ) {
	_lastIndex = 0;
	_rows = rows - 2;
	_cols = cols - 2;
	_freelist = new Cell [(_rows) * (_cols)]; 
	populate();
}

Freepool::~Freepool() {

}

void Freepool::populate() {
	for (int i = 1; i <= numRows(); i++) {
		for (int j = 1; j <= numCols(); j++) {
			_freelist[_lastIndex] = Cell(i, j);
			_lastIndex++;	
		}
	}
}

void Freepool::print() {
	std::cout << "lastIndex: " << _lastIndex << std::endl;
	for (int i = 0; i < _lastIndex; i++) {
		std::cout << "index " << i << ": ";
		_freelist[i].print();
	}
}

void Freepool::insert( Cell cell ) { 
	_freelist[_lastIndex] = cell;
	_lastIndex++;
}

void Freepool::remove( int v ) { // takes in an index to remove
	_freelist[v] = _freelist[_lastIndex - 1];
	_lastIndex--;	
}

Cell Freepool::getMunchiePosition() {
// generates a random munchie position that is free for the grid class
	return _freelist[rand() % _lastIndex];
}

Cell Freepool::atIDX( int v ) {
	return _freelist[v];
}

Cell *Freepool::listOfFreepool() {
	return _freelist;
}

