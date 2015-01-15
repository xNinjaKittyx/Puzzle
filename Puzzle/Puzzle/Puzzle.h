#ifndef MY_PUZZLE_H
#define MY_PUZZLE_H
 
#include <iostream>     //For supporting console input / output
#include <vector>       //For using a vector to store fully explored puzzle configurations 
#include <stdlib.h>

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
 
 
 
class Puzzle
{
 public:      //The following members can be called anywhere
 
       Puzzle(int dimensionValue = 3);
       //The constructor method to initialize the dimension of the puzzle
       //     If dimension is not provided when a Puzzle object is created,
       //     the defaul is to make it a 3 by 3 puzzle.
 
 
       void Display();            //display the puzzle
       void readPuzzle();         //read the puzzle from console input
 
       bool canMoveUp();         
//check whether we can move the space cell up and return true or false accordingly.
 
       bool canMoveDown();       
//check whether we can move the space cell up and return true or false accordingly.
 
       bool canMoveLeft();       
//check whether we can move the space cell up and return true or false accordingly.
 
       bool canMoveRight();    
//check whether we can move the space cell up and return true or false accordingly.
 
       bool moveUp();          
//move the space cell up (and return true) if possible; otherwise return false.
 
       bool moveDown();          
//move the space cell down (and return true) if possible; otherwise return false.
 
       bool moveLeft();          
//move the space cell left (and return true) if possible; otherwise return false.
 
       bool moveRight();         
//move the space cell right (and return true) if possible; otherwise return false.
 
       Puzzle getUpNeighbor();  //get the neighbor reached when move up
       Puzzle getDownNeighbor();  //get the neighbor reached when move down
       Puzzle getLeftNeighbor();  //get the neighbor reached when move left
       Puzzle getRightNeighbor(); //get the neighbor reached when move right
 
       bool isInOrder();          //check whether the puzzle is solved with all the cells in order
 
       void setRandomLayout();          //Set a random puzzle layout
       void interactWithConsole();      //Interact with the user through the console
       void showMenu();                 //Show the menu
       void demoTest();                 //Demostrate the testing of some methods
 
 
 
      
       bool findSolution();        
      //search to find a shortest solution by calling
      //one of the following implementation of breadth-first search
 
       bool searchSolution_BFS_vector();
		//breadth-first search for solution using vectors
 
       bool searchSolution_BFS_BST();   
		//breadth-first search for solution using a binary search tree +vectors
 
 
 
       bool operator==(Puzzle anotherPuzzle);
       //Define the equality relational operator for comparing puzzles
       //needed for comparing puzzles stored in a binary search tree.
 
       bool operator<(const Puzzle anotherPuzzle)const;
        //Define the less than relational operator for comparing puzzles
        //needed for comparing puzzles stored in a binary search tree.
 
 
       friend ostream & operator<< (ostream & output, const Puzzle & aPuzzle);
       //Define the global output operator so that we can wtite code like
       //  output << aPuzzle;
       //to write a puzzle into file outputstream object.
     
 private:
 
        int size;      
//The size of the puzzle, i.e. the number of rows and columns of the puzzle
//      by default size is 3, and the puzzle has a layout of 3 by 3
 
        vector< vector<int> > layout;  
// layout is a vector of vector of integers to record
        // the current layout of the puzzle.
        // layout[i][j] stores the number appearing on row i and column j of the puzzle.
//
        // For the empty cell,
// we use the number 0 to indicate that the cell should be display as an empty cell.
 
 
        // The following two data members record the current location of the empty cell.
        // In other words, the empty cell is currently at row space_i and column space_j
// of the puzzle and the contents of layout[space_i] [ space_j] is 0.
        int space_i;            //The space cell is in layout[space_i][space_j] of the
        int space_j;            //the puzzle.
 
 
 
};
 
 
#endif
 
 
 
 