#include "Puzzle.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
	char input;
	//I will use WASD instead of the IJKM controls because those are more natural for a game.
	char const UP = 'w';
	char const DOWN = 's';
	char const LEFT = 'a';
	char const RIGHT = 'd';
	char const m = 'm';
	char const r = 'r';
	char const f = 'f';
	char const t = 't';
	char const questionmark = '?';

	srand( (unsigned int)time(NULL));
	bool inservice = true;
	cout << "Welcome to n^2-1 game. Type ? for Menu." << endl;

	
	Puzzle dan;
	
	dan.Display();
	while(inservice == true)
	{

		while (dan.isInOrder() == false)
		{
			char input;
			input=_getch();
			if (input == UP)
				dan.moveUp();
			else if (input == DOWN)
				dan.moveDown();
			else if (input == LEFT)
				dan.moveLeft();
			else if (input == RIGHT)
				dan.moveRight();
			else if (input == m)
				dan.readPuzzle();
			else if (input == r)
				dan.setRandomLayout();
			else if (input == f)
			{
				if (dan.findSolution() == true)
				{
					cout << "Answer was found." << endl << endl;
				}
				else
				{
					cout << "There is no answer." << endl << endl;
				}
			}
			else if (input == t)
				;
			else if (input == questionmark)
				dan.showMenu();
			else 
				cout << "Invalid Output" << endl;
			

			dan.Display();
		}

		cout << "Congratz, You finished the puzzle! Press any button to go again" << endl;
		char again;
		again=_getch();

		dan = Puzzle();
	}
	char exit;
	cin >> exit;

	return 0;
}