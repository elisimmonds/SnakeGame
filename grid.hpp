// Eli Simmonds
// CS315 lab05
// grid.hpp

#ifndef GRID_H
#define GRID_H

#include <array>
#include <stdlib.h>

#include "freepool.hpp"
#include "worm.hpp"

class Grid {
public:
	Grid( int rows, int cols );
	~Grid();

	void populate();

	int numRows()	{ return _rows; }
	int numCols()	{ return _cols;	}
	int size()	{ return _cols * _rows; }
	void insert( int row, int col );
	void remove( int row, int col );
	void createMunchie();
	void removeMunchie();
	bool isWall( int row, int col );
	void print();

	void setWorm( Worm *worm )	{ _worm = worm; }
	void setFreepool( Freepool *freepool )	{ _freepool = freepool; }

private:
	int _rows, _cols;
	int **_gridArray;
	
	Worm *_worm;
	Freepool *_freepool;
};

#endif
