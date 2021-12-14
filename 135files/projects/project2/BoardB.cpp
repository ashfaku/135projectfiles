#include "Board.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
using std::cout;
using std::endl;
/*Board::Board()
{
	numRows = 3;
    	numCols = 3;
	panel = new int*[3];
	target = 32;
	max = 0;
	for (int i = 0; i < 3; i++)
		panel[i] = new int[3];
}

//construct a 3 x 3 panel
Board::Board(int m)
{
	if (m >= 1)
	{
		numRows = m;
		numCols = m;
	}
	else
	{

		numRows = 3;
		numCols = 3;
	}
	target = 32;
	max = 0;
	panel = new int*[numRows];
	for (int i = 0; i < numRows; i++)
		panel[i] = new int[numCols];
}

//construct a m x m panel

Board::Board(int m, int n)
{
	if (m >= 1)
		numRows = m;
	else
		numRows = 3;
	if (n >= 1)
		numCols = n;
	else
		numCols = 3;
	max = 0;
	target = 32;
	panel = new int*[numRows];
	for (int i = 0; i < m; i++)
		panel[i] = new int[numCols];
}

 //construct a m x n panel
*/
Board::~Board()
{
	for(int i = 0; i < sizeof(panel) / sizeof(panel[0]); i++)
		delete[] panel[i];
	delete[] panel;
}
//destructor

void Board::print() const
{
	for (int i = 0; i < numRows; i++)
	{
		for (int h = 0; h < numCols; h++)
			cout << "+----";
		cout << "+" << endl;
		for (int h = 0; h < numCols; h++)
		{
			cout << "|";
			if (panel[i][h] != 0)
				cout << std::setw(4) << panel[i][h];
			else
				cout << "    ";
		}
		//	cout << "|    ";
		cout << "|" << endl;
	}
	for (int h = 0; h < numCols; h++)
		cout << "+----";
	cout << "+" << endl;
}

void Board::selectRandomCell(int& row, int& col)
{
	std::vector<int> list;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			if (panel[i][j] == 0)
				list.push_back(i*numCols + j);
	}
	if (list.size() > 0)
	{
		int c = rand() % list.size() + 0;
		c = list.at(c);
		row = c / numCols;
		col = c % numCols;
		panel[row][col] = 1;
		Board::print();
	}
	if (noAdjacentSameValue() || list.size() == 0)
		cout << "Game over. Try again." << endl;
}
bool Board::noAdjacentSameValue() const
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 1; j < numCols - 1; j++)
		{
			if (panel[i][j-1] == panel[i][j] || panel[i][j+1] == panel[i][j])
				return false;
		}
	}
	return true;
}

