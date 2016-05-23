// Eli Simmonds
// CS315 lab05
// grid.cpp

#include "grid.hpp"

Grid::Grid( int row, int col ) {
	_rows = row;
	_cols = col;
	_gridArray = new int *[row];
	for (int i = 0; i < row; i++) {
		_gridArray[i] = new int [col];
	}
}




void Grid::populate() {
	int count = 0;
	for (int i = 0; i < numRows(); i++) {
		for (int j = 0; j < numCols(); j++) {	
			if (i == 0 || i == numRows() - 1 || j == 0 || j == numCols() - 1) {
				_gridArray[i][j] = -1;
			}
			else {
				_gridArray[i][j] = count;
				count++;
			}
		}
	}
}

void Grid::insert( int row, int col ) {
	_gridArray[row][col] = _freepool->lastIndex();
	_freepool->insert( Cell(row, col) );
}

void Grid::remove ( int row, int col ) {
	int idx = _gridArray[row][col];
	_gridArray[row][col] = -1;
	Cell c = Cell(row, col);
	_freepool->remove(idx);
	_gridArray[_freepool->atIDX(idx).row()][_freepool->atIDX(idx).column()] = idx;
}

void Grid::createMunchie() {
}

void Grid::removeMunchie() {

}

bool Grid::isWall( int row, int col ) {
	if (_gridArray[row][col] == -1)
		return true;
	return false;
}

void Grid::print() {
	for (int i = 0; i < numRows(); i++) {
		for (int j = 0; j < numCols(); j++) {
			std::cout << _gridArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


