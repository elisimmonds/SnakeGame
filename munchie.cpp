// Eli Simmonds
// CS315 Lab05
// munchie.cpp

#include "munchie.hpp"

Munchie::Munchie ( Cell cell ) {
	_row = cell.row(); // should row and col be assigned randomly from freepool?
	_col = cell.column();
	_size = rand() % 10; // sets size to a number between 1-9
}

Munchie::~Munchie() {

}

int Munchie::row() {
	return _row;
}

int Munchie::column() {
	return _col;
}

int Munchie::size() {
	if (_size == 0)
		return _size + 1;
	else if (_size == 10)
		return _size - 1;
	return _size;
}
