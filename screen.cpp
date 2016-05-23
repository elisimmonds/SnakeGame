#include <curses.h>
#include "getChar.hpp"
#include "freepool.hpp"
#include "grid.hpp"
#include "worm.hpp"
#include "munchie.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "sstream"

void startup( void );
void terminate( void );
void drawScreen( int rows, int cols, Grid *grid );
Cell getInput( char key, Cell head );
void gameOver( int score );
int queryRows(void);
int queryCols(void);


int main(void)
{
	int rows = queryRows();
	int cols = queryCols();

	startup(); // starts the game and draws screen

	Freepool *fpool = new Freepool(rows, cols);
	Grid *grid = new Grid(rows, cols);
	grid->populate();
	grid->setFreepool( fpool );
	Worm *worm = new Worm(grid->size());
	grid->setWorm(worm);

	drawScreen( rows, cols, grid );
	refresh();

	int headRow = rows/2;
	int headCol = cols/2 - 4;
	Cell head = Cell(headRow, headCol);
	for (int i = 0; i < 7; i++) {	// creates the initial worm
		head = Cell(headRow, headCol + i);
		worm->insertHead(head);
		grid->remove( head.row(), head.column() );
		mvaddch(head.row() + 1, head.column(), 'o'); // draw body one by one
	}
	mvaddch(head.row() + 1, head.column(), '@');	// draws initial worm head

	// create intial count
	int score = 0;
	int munchieCount = 0;
	bool game = true;
	char key;
	char temp = 'l';	// default starting char
	Cell tail;
	Munchie munchie = Munchie (fpool->getMunchiePosition());
	int munchSize = munchie.size();
	std::string convertStr = std::to_string(munchSize);
	const char *intChar = convertStr.c_str();
	mvaddstr(munchie.row() + 1, munchie.column(), intChar);
	mvaddstr(0, 0, "Worm");
	mvaddstr(0, cols - 7, "Score: 0");
	refresh();
	while (game == true) {
		key = get_char();
		mvaddch(head.row() + 1, head.column(), 'o');
		if (key == ' ') // covers the null entry case at beggining
			head = getInput( temp, head );
		else
			head = getInput( key, head );

		mvaddch(head.row() + 1, head.column(), '@');
		
		if (key != ' ' && grid->isWall( head.row(), head.column() )) {
			game = false;	// if you ran into a wall
		}
		else if (head.row() == munchie.row() && head.column() == munchie.column()) {
			score += munchie.size();		// iterates score
			convertStr = std::to_string(score);	// and gets a new munchie
			intChar = convertStr.c_str();
			mvaddstr(0, cols, intChar);
			munchieCount += munchie.size();
			munchie = Munchie(fpool->getMunchiePosition());
			munchSize = munchie.size();
			convertStr = std::to_string(munchSize);
			intChar = convertStr.c_str();
			mvaddstr(munchie.row() + 1, munchie.column(), intChar);
		}
		if (munchieCount > 0) {
			grid->remove(head.row(), head.column());	// grows the worm	
			worm->insertHead(head);				// till all munchies 
			munchieCount--;					// are eaten
		}
		else {
			grid->remove(head.row(), head.column());	// moves the worm
			worm->insertHead(head);				// and deletes tail segment
			tail = worm->removeTail();
			mvaddch(tail.row() + 1, tail.column(), ' ');	
			grid->insert( tail.row(), tail.column() );
		}
		if ( key != ' ')
			temp = key;	// makes sure the worm is getting a char
		refresh();
	}

	terminate();
	gameOver( score );
}

Cell getInput( char key, Cell head ) {
// takes in a key as input and moves the snake head accordingly
	if (key == 'k') {	// go up
		return Cell(head.row() - 1, head.column());
	}
	else if (key == 'j') {	// go down
		return Cell(head.row() + 1, head.column());
	}
	else if (key == 'h') {	// go left
		return Cell(head.row(), head.column() - 1);
	}
	else if (key == 'l') {	// go right
		return Cell(head.row(), head.column() + 1);
	}
	else {
		terminate();
		std::cout << "You entered the wrong key!" << std::endl;
	}

    return head;
}

void gameOver( int score ) {
// draws to the screen that the game is over and ends it.
	std::cout << "The worm died since it ran into something!" << std::endl;
	std::cout << "Your final score was: " << score << std::endl;
}

void startup( void ) {
	initscr();	 /* activate the curses */
	curs_set(0);/* do not display the cursor */
	clear();	 /* clear the screen that curses provides */
	noecho();	 /* prevent the input chars to be echoed to the screen */
	cbreak();	 /* change the stty so that characters are delivered to the
			program as they are typed--no need to hit the return key!*/
}

void terminate( void )
{
	 mvcur( 0, COLS - 1, LINES - 1, 0 );
	 clear();
	 refresh();
	 endwin();
}

void drawScreen( int rows, int cols, Grid *grid ) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (grid->isWall(r, c))
				mvaddch(r + 1, c, '*');
			else
				mvaddch(r + 1, c, ' ');		
		}
	}

}	

int queryRows() {
	int row;
	std::cout << "How many rows? (9-25) ";
	std::cin >> row;
	if (row < 9)
		row = 9;
	if (row > 25) 
		row = 25;
	return row;
}

int queryCols() {
	int col;
	std::cout << "How many cols? (9-80) ";
	std::cin >> col;
	if (col < 9)
		col = 9;
	if (col > 80) 
		col = 80;
	return col;
}
