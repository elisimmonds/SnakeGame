all: screen.x

FLAGS = -ggdb -std=c++11 -Wall -Wextra

screen.x:  screen.o getChar.o cell.o munchie.o worm.o freepool.o grid.o
	g++ $(FLAGS) -o screen.x screen.o getChar.o cell.o munchie.o worm.o freepool.o grid.o -lcurses -ltermcap

screen.o: screen.cpp
	g++ $(FLAGS) -c screen.cpp -o screen.o -lcurses -ltermcap

getChar.o: getChar.cpp 
	gcc -c -ggdb getChar.cpp -o getChar.o -lcurses -ltermcap

cell.o: cell.cpp
	g++ $(FLAGS) -c cell.cpp -o cell.o

munchie.o: munchie.cpp
	g++ $(FLAGS) -c munchie.cpp -o munchie.o

worm.o: worm.cpp
	g++ $(FLAGS) -c worm.cpp -o worm.o

freepool.o: freepool.cpp
	g++ $(FLAGS) -c freepool.cpp -o freepool.o

grid.o: grid.cpp
	g++ $(FLAGS) -c grid.cpp -o grid.o

clean:
	/bin/rm -f screen.x *.o *~
