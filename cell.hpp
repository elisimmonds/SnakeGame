// Eli Simmonds
// Lab05 CS315
// cell.hpp

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <stdlib.h>

class Cell {
public:
	Cell();
	Cell( int row, int col ); // creates a cell object with row/col
	~Cell();		// destructor for cell class
	int row();		// returns row
	int column();		// returns column
	void print();
private:
	int _row;
	int _col;
};

#endif
