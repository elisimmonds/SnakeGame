// Eli Simmonds
// CS315 lab05
// cell.cpp

#include "cell.hpp"

Cell::Cell() {
// default for creating array
}

Cell::Cell( int row, int col ) {
	_row = row;
	_col = col;
}

Cell::~Cell() {
}

int Cell::row() {
	return _row;
}

int Cell::column() {
	return _col;
}

void Cell::print() {
	std::cout << "row: " << _row << " col: " << _col << std::endl;
}
