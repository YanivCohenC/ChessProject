#include "King.h"

King::King(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char King::move(Pieces* arr[8][8], string dst)
{
	char ans = '0';
	if (_taken != true || _side[0] != dst[4])
	{
		ans = '2';
	}
	else if (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken() && this != arr[int('8' - dst[3])][int(dst[2] - 'a')])
	{
		ans = '3';
	}
	/*else if (check(arr, dst))
	{
		ans = '4';
	}*/
	else if ((dst[1] > '8' || dst[1] < '0') || (dst[3] > '8' || dst[3] < '0') || (dst[0] > 'h' || dst[0] < 'a') || (dst[2] > 'h' || dst[2] < 'a'))
	{
		ans = '5';
	}
	else if (squareCheck(arr, dst))
	{
		ans = '6';
	}
	else if (_location[0] == dst[2] && _location[1] == dst[3])
	{
		ans = '7';
	}
	return ans;
}


/*
The movement of the king
*/
bool King::squareCheck(Pieces* arr[8][8], string dst)
{
	bool ans = true;
	int x = ('8' - dst[3]), y = (dst[2] - 'a');

	// THIS WORKS WELL
	if (dst[0] == dst[2] && (dst[1] + 1 == dst[3] || dst[1] - 1 == dst[3])) // Up or down check
	{
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	// THIS WORKS WELL
	else if (dst[1] == dst[3] && (dst[0] + 1 == dst[2] || dst[0] - 1 == dst[2])) // Left or right check
	{
		char ch = arr[x][y]->getSide()[0];
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	// THIS NEEDS FIXING
	else if ((dst[0] == dst[2] + 1 && dst[1] == dst[3] + 1) || (dst[1] == dst[3] - 1 && dst[2] == dst[0] - 1)) // Upper right or lower left check
	{
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	// THIS NEEDS FIXING
	else if ((dst[0] == dst[2] - 1 && dst[1] == dst[3] - 1) || (dst[1] == dst[3] + 1 && dst[2] == dst[0] + 1)) // Upper left or lower right check
	{
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	return ans;
}


bool King::check(Pieces* arr[8][8], string dst)
{
	bool ans = false;
	if (rookCheck(arr, dst) || bishopCheck(arr, dst) || knightCheck(arr, dst))
	{
		ans = true;
	}
	return ans;
}


bool King::rookCheck(Pieces* arr[8][8], string dst)
{
	bool ans = false;
	int x = int('8' - dst[3]), y = int(dst[2] - 'a');
	if (left(arr, dst, y, 0, x) || right(arr, dst, y, 8, x) || up(arr, dst, x, 0, y) || down(arr, dst, x, 8, y))
	{
		ans = true;
	}
	return ans;
}


bool King::bishopCheck(Pieces* arr[8][8], string dst)
{
	int x = int('8' - dst[3]), y = int(dst[2] - 'a');
	bool ans = false;
	if (upLeft(arr, dst, x, y, 0) || upRight(arr, dst, x, y, 8) || downLeft(arr, dst, x, y, 0) || downRight(arr, dst, x, y, 8))
	{
		ans = true;
	}
	return ans;
}


bool King::knightCheck(Pieces* arr[8][8], string dst)
{
	bool ans = false;
}



bool King::upLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX - 1, j = startY - 1; j >= dstY; i--, j--)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if ( j != dstY && arr[i][j]->getSide()[0] != 'n' && arr[i][j]->getSide()[0] != dst[4])
			{
				if (arr[i][j]->getType()[0] == 'b' || arr[i][j]->getType()[0] == 'q' || (arr[i][j]->getType()[0] == 'p' && arr[i][j]->getSide()[0] == 'W') || arr[i][j]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}
	return ans;
}


bool King::upRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX - 1, j = startY + 1; j <= dstY; i--, j++)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if (j != dstY && arr[i][j]->getSide()[0] != 'n')
			{
				if (arr[i][j]->getType()[0] == 'b' || arr[i][j]->getType()[0] == 'q' || (arr[i][j]->getType()[0] == 'p' && arr[i][j]->getSide()[0] == 'W') || arr[i][j]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}
	return ans;
}


bool King::downLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX + 1, j = startY - 1;j >= dstY; i++, j--)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if (j != dstY && arr[i][j]->getSide()[0] != 'n')
			{
				if (arr[i][j]->getType()[0] == 'b' || arr[i][j]->getType()[0] == 'q' || (arr[i][j]->getType()[0] == 'p' && arr[i][j]->getSide()[0] == 'B') || arr[i][j]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}
	return ans;
}


bool King::downRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX + 1, j = startY + 1;j <= dstY; i++, j++)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if (j != dstY && arr[i][j]->getSide()[0] != 'n')
			{
				if (arr[i][j]->getType()[0] == 'b' || arr[i][j]->getType()[0] == 'q' || (arr[i][j]->getType()[0] == 'p' && arr[i][j]->getSide()[0] == 'B') || arr[i][j]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}
	return ans;
}




bool King::left(Pieces* arr[8][8], string dst, int startY, int dstY, int X)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startY - 1; i >= dstY; i--)
	{
		if (arr[X][i]->getTaken() && this != arr[X][i])
		{
			if (i != dstY && arr[X][i]->getSide()[0] != 'n')
			{
				if (arr[X][i]->getType()[0] == 'r' || arr[X][i]->getType()[0] == 'q' || arr[X][i]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}

	return ans;
}


bool King::right(Pieces* arr[8][8], string dst, int startY, int dstY, int X)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startY + 1; i <= dstY; i++)
	{
		if (arr[X][i]->getTaken() && this != arr[X][i])
		{
			if (i != dstY && arr[X][i]->getSide()[0] != 'n')
			{
				if (arr[X][i]->getType()[0] == 'r' || arr[X][i]->getType()[0] == 'q' || arr[X][i]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}

	return ans;
}


bool King::up(Pieces* arr[8][8], string dst, int startX, int dstX, int Y)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX - 1; i >= dstX; i--)
	{
		if (arr[i][Y]->getTaken() && this != arr[i][Y])
		{
			if (i != dstX && arr[i][Y]->getSide()[0] != 'n')
			{
				if (arr[i][Y]->getType()[0] == 'r' || arr[i][Y]->getType()[0] == 'q' || arr[i][Y]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}
	return ans;
}


bool  King::down(Pieces* arr[8][8], string dst, int startX, int dstX, int Y)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX + 1; i <= dstX; i++)
	{
		if (arr[i][Y]->getTaken() && this != arr[i][Y])
		{
			if (i != dstX && arr[i][Y]->getSide()[0] != 'n')
			{
				if (arr[i][Y]->getType()[0] == 'r' || arr[i][Y]->getType()[0] == 'q' || arr[i][Y]->getType()[0] == 'k')
				{
					ans = true;
					break;
				}
			}
		}
	}
	return ans;
}
