// Eli Simmonds
// CS315 Lab05
// README.txt

Everything appears to work.

Controls
- Control the worm with the default controls.
- h, j, k, l are left, down, up, right respectively.
- Must be using lowercase to play the game.

Cell class
- Creates a cell with a row and col
- Retrieve row/col with row() and column()
- print the cell info with print()

Munchie class
- Create a munchie by passing in a cell
- row() column() and size() getter functions

Freepool class
- Create a new freepool with the size of rows and cols
- populate it with values (-1 is wall) using populate
- Inserts a cell and removes an index (int)
- check what cell at index using atIDX(int v)
- Get position for the munchie using getMunchiePosition();
- numRows() numCols() lastIndex() size() getters
- get the array using listOfFreepool()

Grid class
- Pass the constructor the size using row/columns
- Populate the grid with -1's using populate()
- Insert/Remove at a row/col
- Munchies are created and deleted here
- isWall checks for -1 (worm/wall)
- Grid keeps an instance of worm and freepool to keep track.

Worm class
- Create a worm using the size of the board
- Insert head makes the head move
- Remove tail makes it look like the worm is moving
- Size is the size of worm

Screen
- Runs all curses and is the main function
- Takes in row from 9-25 and cols 9-80. If outside of range it changes them to be in range
