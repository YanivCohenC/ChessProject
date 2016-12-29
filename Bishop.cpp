#include "Bishop.h"


Bishop::Bishop(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char Bishop::move(Pieces* arr[][8], string dst)
{
	char ans = '0';
	if (_side[0] != dst[4])
	{
		ans = '2';
	}
	else if (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken() && arr[int('8' - dst[3])][int(dst[2] - 'a')]->getSide()[0] == dst[4] && this->getLocation() != arr[int('8' - dst[3])][int(dst[2] - 'a')]->getLocation())
	{
		ans = '3';
	}
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

*/
bool Bishop::squareCheck(Pieces* arr[][8], string dst)
{
	bool ans = false;
	int x1 = int('8' - dst[1]), x2 = int('8' - dst[3]), y1 = int(dst[0] - 'a'), y2 = int(dst[2] - 'a');

	//move up and right
	if (dst[1] < dst[3] && y1 < y2)
	{

		ans = upRight(arr, dst, x1, y1, x2, y2);
	}
	//move up and left
	else if (dst[1] < dst[3] && y1 > y2)
	{
		ans = upLeft(arr, dst, x1, y1, x2, y2);
	}
	// move down and right
	else if (dst[1] > dst[3] && y1 < y2)
	{
		ans = downRight(arr, dst, x1, y1, x2, y2);
	}
	//move down and left
	else if (dst[1] > dst[3] && y1 > y2)
	{
		ans = downLeft(arr, dst, x1, y1, x2, y2);
	}
	else
	{
		ans = true;
	}


	return ans;
}



bool Bishop::upLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX-1, j = startY-1; i >= dstX && j >= dstY; i--, j--)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if (i != dstX && j != dstY && arr[i][j]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		if ((i == dstX || j == dstY) && dstLoc.compare(arr[i][j]->getLocation()))
		{
			ans = true;
		}
	}
	return ans;
}



bool Bishop::upRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX-1, j = startY+1; i >= dstX && j <= dstY; i--, j++)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if (i != dstX && j != dstY && arr[i][j]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		if ((i == dstX || j == dstY) && dstLoc.compare(arr[i][j]->getLocation()))
		{
			ans = true;
		}
	}
	return ans;
}



bool Bishop::downLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX+1, j = startY-1; i <= dstX && j >= dstY; i++, j--)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if (i != dstX && j != dstY && arr[i][j]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		if ((i == dstX || j == dstY) && dstLoc.compare(arr[i][j]->getLocation()))
		{
			ans = true;
		}
	}
	return ans;
}



bool Bishop::downRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX+1, j = startY+1; i <= dstX && j <= dstY; i++, j++)
	{
		if (arr[i][j]->getTaken() && this != arr[i][j])
		{
			if (i != dstX && j != dstY && arr[i][j]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		if ((i == dstX || j == dstY) && dstLoc.compare(arr[i][j]->getLocation()))
		{
			ans = true;
		}
	}
	return ans;
}
