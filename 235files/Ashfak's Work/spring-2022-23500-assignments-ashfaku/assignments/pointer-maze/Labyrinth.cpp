#include "Labyrinth.h"
#include <iostream>
bool isPathToFreedom(MazeCell* start, const std::string& moves)
{
	int i = 0;
	bool b = false, p = false, w = false;
	while (i < moves.length())
	{
		switch (moves[i])
		{
			case 'N':
				start = start->north;
				break;
			case 'W':
				start = start->west;
				break;
			case 'E':
				start = start->east;
				break;
			case 'S':
				start = start->south;
				break;
		}
		if (start == nullptr)
			return false;
		switch (start->whatsHere)
		{
			case Item::POTION:
				p = true;
				break;
			case Item::WAND:
				w = true;
				break;
			case Item::SPELLBOOK:
				b = true;
				break;
			default:
				break;
		}
		i++;
	}
	return b && p && w;
}
