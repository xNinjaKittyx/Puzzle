#include "Puzzle.h"
#include <iostream>     //For supporting console input / output
#include <vector>       //For using a vector to store fully explored puzzle configurations 
#include <stack>

#include <map> 
//For using a map (a search tree) to map a puzzle configuration to its parent puzzle configuration.
//Not needed if you use your own data structures to store the parent information.
 
#include <deque>       
//For using a deque as a frontier queue in breadth-first search
//Not needed if you use your own linked list or other data structures to store the frontier.
 
#include <algorithm>
//For using the 'find' generic algorithm to search a vector of explored puzzle configurations
//Not needed if you just write your own code to search the vector.
 
#include <fstream>      //For file input / output
 
#include <ctime>        //For using time to start a random seed
 
#include <conio.h>     
//You don’t need <conio.h> at all (and it only works on Windows platform)
//      if the user is required to press the Enter key after keying in the option character.
//In this case, just use cin >> option for reading the option character.
//
//If you do want to allow the user to key in the option character only
//      without the need to press the Enter key after the character,
//      on Windows platform you can do option=_getch() to get the character input
//      by calling _getch().
 
//Using <conio.h> not a good practice since it is NOT in the C++ standard,
//      but you may use it on Windows platform to have the support of getch()
//      for reading a character from the keyboard without pressing the Enter key.
 
 
using namespace std;
 
Puzzle::Puzzle(int dimensionValue)
//The constructor method to initialize the dimension of the puzzle
//     If dimension is not provided when a Puzzle object is created,
//     the defaul is to make it a 3 by 3 puzzle.
{
	size = dimensionValue;
	int num = size*size;
	layout.resize(size);
	for(int i=0;i<size;i++)
		layout[i].resize(size);
		
	vector<int> x;
	for (int i=0;i<num;i++)
	{
		x.push_back(i);
	}

	random_shuffle(x.begin(), x.end());



	int k = 0; //This is for the x vector count.
	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size;j++)
		{
			layout[i][j] = x[k];
			if (layout[i][j] == 0)
			{
				space_i = i;
				space_j = j;
			}
			k++;
		}
	}
}
 
 
void Puzzle::Display()
{
	cout << "=========================" << endl;
	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size;j++)
		{
			if (layout[i][j] == 0)
				cout << "    ";
			else
				cout << layout[i][j] << "   ";
		}
		cout << endl;
	}
	cout << "=========================" << endl;
}

void Puzzle::readPuzzle()
{
	int tempsize;
	cout << "What is the size of the Puzzle? (Integer)" << endl;
	cin >> tempsize;
	while (tempsize < 1 || cin.fail())
	{
		cout << "Invalid Puzzle Size" << endl;
		cout << "Please type a valid size. (Integer)" << endl;
		cin >> tempsize;
	}
	vector< vector<int> > templayout;
	int num = tempsize * tempsize;

	templayout.resize(tempsize);
	for(int i=0;i<tempsize;i++)
		templayout[i].resize(tempsize);

	//For now I will make it one by one, Switch to getline when I have time."
	for (int i=0;i<tempsize;i++)
	{
		cout << "Row " << i+1 << ":" << endl;
		for (int j=0;j<tempsize;j++)
		{
			int input;
			cout << "Column " << j+1 << ":";
			cin >> input;
			while (input < 0 || input > num)
			{
				cout << "Numberi  outside parameters. Please enter another number" << endl;
				cin >> input;
			}
			templayout[i][j]=input;
		}
	}

	int tempspacei;
	int tempspacej;
	bool repeated = false;
	//check if legit puzzle

	for (int i=0;i<tempsize;i++)
	{
		for (int j=0;j<tempsize;j++)
		{
			//Checking if the number repeats
			for (int a=0;a<tempsize;a++)
			{
				for (int b=0;b<tempsize;b++)
				{
					if (i != a && j != b)
					{
						if (templayout[i][j] == templayout[a][b])
						{	
							repeated = true;
							break;
						}
					}
				}
				if (repeated == true)
				{
					break;
				}
			}
			if (repeated == true)
				break;

			if (templayout[i][j] == 0)
			{
				tempspacei = i;
				tempspacej = j;
			}
		}
		if (repeated == true)
			break;
	}
	if (repeated == true)
		cout << "A number was repeated. Please retry again" << endl;
	else
	{
		space_i = tempspacei;
		space_j = tempspacej;
		size = tempsize;
		
		for (int i = 0;i<size;i++)
		{
			for (int j = 0;j<size;j++)
			{
				layout[i][j] = templayout [i][j];
			}
		}
		cout << "Puzzle Implemented" << endl;
	}


}         //Input a puzzle into the program.
 
bool Puzzle::canMoveUp()
{
	for (int i=0; i<size;i++)
	{
		if (layout[space_i][space_j] == layout[0][i])
			return false;
	}
	return true;
}         
//check whether we can move the space cell up and return true or false accordingly.
 
bool Puzzle::canMoveDown()
{
	for (int i=0; i<size;i++)
	{
		if (layout[space_i][space_j] == layout[size-1][i])
			return false;
	}
	return true;
}       
//check whether we can move the space cell up and return true or false accordingly.
 
bool Puzzle::canMoveLeft()
{
	for (int i=0; i<size;i++)
	{
		if (layout[space_i][space_j] == layout[i][0])
			return false;
	}
	return true;
}       
//check whether we can move the space cell up and return true or false accordingly.
 
bool Puzzle::canMoveRight()
{
	for (int i=0; i<size;i++)
	{
		if (layout[space_i][space_j] == layout[i][size-1])
			return false;
	}
	return true;
}    
//check whether we can move the space cell up and return true or false accordingly.
 
bool Puzzle::moveUp()
{
	if (canMoveUp())
	{
		int temp = layout[space_i-1][space_j];
		layout[space_i-1][space_j] = layout[space_i][space_j];
		layout[space_i][space_j] = temp;
		space_i--;
		return true;
	}
	
	return false;
}          
//move the space cell up (and return true) if possible; otherwise return false.
 
bool Puzzle::moveDown()
{
	if (canMoveDown())
	{
		int temp = layout[space_i+1][space_j];
		layout[space_i+1][space_j] = layout[space_i][space_j];
		layout[space_i][space_j] = temp;
		space_i++;
		return true;
	}
	
	return false;
}          
//move the space cell down (and return true) if possible; otherwise return false.
 
bool Puzzle::moveLeft()
{
	if (canMoveLeft())
	{
		int temp = layout[space_i][space_j-1];
		layout[space_i][space_j-1] = layout[space_i][space_j];
		layout[space_i][space_j] = temp;
		space_j--;
		return true;
	}
	
	return false;
}          
//move the space cell left (and return true) if possible; otherwise return false.
 
bool Puzzle::moveRight()
{
	if (canMoveRight())
	{
		int temp = layout[space_i][space_j+1];
		layout[space_i][space_j+1] = layout[space_i][space_j];
		layout[space_i][space_j] = temp;
		space_j++;
		return true;
	}
	
	return false;
}         
//move the space cell right (and return true) if possible; otherwise return false.
 
Puzzle Puzzle::getUpNeighbor()
{
	Puzzle temp(size);
	temp.layout = layout;
	temp.space_i = space_i;
	temp.space_j = space_j;
	temp.moveUp();
	return temp;
}  //get the neighbor reached when move up
Puzzle Puzzle::getDownNeighbor()
{
	Puzzle temp(size);
	temp.layout = layout;
	temp.space_i = space_i;
	temp.space_j = space_j;
	temp.moveDown();
	return temp;
}  //get the neighbor reached when move down
Puzzle Puzzle::getLeftNeighbor()
{
	Puzzle temp(size);
	temp.layout = layout;
	temp.space_i = space_i;
	temp.space_j = space_j;
	temp.moveLeft();
	return temp;
}  //get the neighbor reached when move left
Puzzle Puzzle::getRightNeighbor()
{
	Puzzle temp(size);
	temp.layout = layout;
	temp.space_i = space_i;
	temp.space_j = space_j;
	temp.moveRight();
	return temp;
} //get the neighbor reached when move right
 
bool Puzzle::isInOrder()
{
	int num = size*size;
	int count = 1;
	for (int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if (layout[i][j] == layout[size-1][size-1])
			{
				if (layout[i][j] == 0)
					return true;
			}
			else if (layout[i][j] != count)
				return false;
			else
				count++;
		}
	}

}          //check whether the puzzle is solved with all the cells in order
 
void Puzzle::setRandomLayout()
{
	//This code errors really weirdly. Instead I implemented 
	cout << "Input Puzzle Size(Integer): ";
	int tempsize;
	cin >> tempsize;
	while (tempsize < 2 || cin.fail())
	{
		cout << "Invalid Puzzle." << endl
			 << "Input Puzzle Size (Integer): ";
		cin >> tempsize;
	}
	Puzzle temp(tempsize);
	layout = temp.layout;
	size = temp.size;
	space_i = temp.space_i;
	space_j = temp.space_j;

}          //Set a random puzzle layout
void Puzzle::interactWithConsole()
{

}      //Interact with the user through the console
void Puzzle::showMenu()
{
	cout << "==========================Help Menu==========================" << endl
		 << "                          Controls                           " << endl
		 << "wasd - To move the empty space Up, Left, Down, Right" << endl
		 << "                     Puzzle Generation                       " << endl
		 << "m - Specify a puzzle through keyboard input." << endl
		 << "r - randomly generate a puzzle." << endl
		 << "f - Automatically search for a soluation" << endl
		 << "t - Testing the public methods of the puzzle class - not available" << endl
		 << "? - Display this help menu" << endl
		 << "=============================================================" << endl;

}                 //Show the menu
void Puzzle::demoTest()
{
}                 //Demostrate the testing of some methods
 
 
 
      
bool Puzzle::findSolution()
{
	deque<Puzzle> Q;
	vector<Puzzle> V;

	Puzzle t; //examined Puzzle sequence

	//Copy all current Puzzle variables into another puzzle class;
	Puzzle troll(size);
	troll.layout = layout;
	troll.space_i = space_i;
	troll.space_j = space_j;

	V.push_back(troll);

	Q.push_back(troll);

	while(!Q.empty())
	{
		t = Q.front();

		t.Display();

		if (t.isInOrder())
			return true;

		Q.pop_front();
		//IF PUZZLE CAN MOVE UP
		if (t.canMoveUp() == true)
		{
			Puzzle temp = t.getUpNeighbor();
			bool seen = false;
			//Check if this sequence was seen before;
			for (int x=0;x<V.size();x++)
			{
				if (temp.layout == V[x].layout)
				{
					seen = true;
					break;
				}
			}
			if (seen == false)
			{
				Q.push_back(temp);
				V.push_back(temp);
			}
		}

		//IF PUZZLE CAN MOVE DOWN
		if (t.canMoveDown() == true)
		{
			Puzzle temp = t.getDownNeighbor();
			bool seen = false;
			//Check if this sequence was seen before;
			for (int x=0;x<V.size();x++)
			{
				if (temp.layout == V[x].layout)
				{
					seen = true;
					break;
				}
			}
			if (seen == false)
			{
				Q.push_back(temp);
				V.push_back(temp);
			}
		}

		//IF PUZZLE CAN MOVE LEFT
		if (t.canMoveLeft() == true)
		{
			Puzzle temp = t.getLeftNeighbor();
			bool seen = false;
			//Check if this sequence was seen before;
			for (int x=0;x<V.size();x++)
			{
				if (temp.layout == V[x].layout)
				{
					seen = true;
					break;
				}
			}
			if (seen == false)
			{
				Q.push_back(temp);
				V.push_back(temp);
			}
		}

		//IF PUZZLE CAN MOVE RIGHT
		if (t.canMoveRight() == true)
		{
			Puzzle temp = t.getRightNeighbor();
			bool seen = false;
			//Check if this sequence was seen before;
			for (int x=0;x<V.size();x++)
			{
				if (temp.layout == V[x].layout)
				{
					seen = true;
					break;
				}
			}
			if (seen == false)
			{
				Q.push_back(temp);
				V.push_back(temp);
			}
		}
	}
	return false;
}
      //search to find a shortest solution by calling
      //one of the following implementation of breadth-first search
 
bool Puzzle::searchSolution_BFS_vector()
{
	return true;
}
//breadth-first search for solution using vectors
 
bool Puzzle::searchSolution_BFS_BST()
{
	return true;
}  
//breadth-first search for solution using a binary search tree +vectors
 
 
 
bool Puzzle::operator==(Puzzle anotherPuzzle)
{	
	if (size != anotherPuzzle.size)
	{
		return false;
	}
	if (space_i != anotherPuzzle.space_i || space_j != anotherPuzzle.space_j)
	{
		return false;
	}
	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size;j++)
		{
			if (layout[i][j] != anotherPuzzle.layout[i][j])
				return false;
		}
	}
	return true;
}
       //Define the equality relational operator for comparing puzzles
       //needed for comparing puzzles stored in a binary search tree.
 
bool Puzzle::operator<(const Puzzle anotherPuzzle)const
{
	return true;
}
        //Define the less than relational operator for comparing puzzles
        //needed for comparing puzzles stored in a binary search tree.
 
 
ostream & operator<< (ostream & output, const Puzzle & aPuzzle)
{
	return output;
}
       //Define the global output operator so that we can wtite code like
       //  output << aPuzzle;
       //to write a puzzle into file outputstream object.

 
 
 
 
 