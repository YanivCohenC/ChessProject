#include "Rook.h"


Rook::Rook(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char Rook::move(Pieces* arr[][8], string dst)
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



/*Function that will check to where the user want to move and will call the right function to check the row or the line
input:
Pieces* arr[][8], string dst
output:
true if there is piece in the way of the rook
false if the way is clear
*/
bool Rook::squareCheck(Pieces* arr[][8], string dst)
{
	bool ans = false;
	int x1 = int('8' - dst[1]), x2 = int('8' - dst[3]), y1 = int(dst[0] - 'a'), y2 = int(dst[2] - 'a');

	//move up
	if (dst[0] == dst[2] && dst[1] < dst[3])
	{
		ans = up(arr, dst, x1, x2, y1);
	}
	//move down
	else if (dst[0] == dst[2] && dst[1] > dst[3])
	{
		ans = down(arr, dst, x1, x2, y1);
	}
	//move left
	else if (dst[0] > dst[2] && dst[1] == dst[3])
	{
		ans = left(arr, dst, y1, y2, x1);
	}
	//move right
	else if (dst[0] < dst[2] && dst[1] == dst[3])
	{
		ans = right(arr, dst, y1, y2, x1);
	}
	else
	{
		ans = true;
	}
	return ans;
}



/*The fucntion will check if the left line is free and there is no pieces in the way of the rook to the dst
input:
Pieces* arr[8][8], string dst, int startY, int dstY, int X
output:
true if there is something in the way that doesnt allow to move to the dst
false if the way is clear
*/
bool  Rook::left(Pieces* arr[8][8], string dst, int startY, int dstY, int X)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startY-1; i >= dstY; i--)
	{
		//checkng if there is piece is the square
		if (arr[X][i]->getTaken() && this != arr[X][i])
		{
			//checking if there is something in the way and not in the dst
			if (i != dstY && arr[X][i]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		//if the for in the last run and the location of currect square not equeal to the dst there is illegal dst
		if (i == dstY && dstLoc.compare(arr[X][i]->getLocation()))
		{
			ans = true;
		}
	}

	return ans;
}


/*The fucntion will check if the right line is free and there is no pieces in the way of the rook to the dst
input:
Pieces* arr[8][8], string dst, int startY, int dstY, int X
output:
true if there is something in the way that doesnt allow to move to the dst
false if the way is clear
*/
bool  Rook::right(Pieces* arr[8][8], string dst, int startY, int dstY, int X)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startY+1; i <= dstY; i++)
	{
		//checkng if there is piece is the square
		if (arr[X][i]->getTaken() && this != arr[X][i])
		{
			//checking if there is something in the way and not in the dst
			if (i != dstY && arr[X][i]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		//if the for in the last run and the location of currect square not equeal to the dst there is illegal dst
		if (i == dstY && dstLoc.compare(arr[X][i]->getLocation()))
		{
			ans = true;
		}
	}

	return ans;
}



/*The fucntion will check if the up row is free and there is no pieces in the way of the rook to the dst
input:
Pieces* arr[8][8], string dst, int startY, int dstY, int X
output:
true if there is something in the way that doesnt allow to move to the dst
false if the way is clear
*/
bool  Rook::up(Pieces* arr[8][8], string dst, int startX, int dstX, int Y)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX-1; i >= dstX; i--)
	{
		//checkng if there is piece is the square
		if (arr[i][Y]->getTaken() && this != arr[i][Y])
		{
			//checking if there is something in the way and not in the dst
			if (i != dstX && arr[i][Y]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		//if the for in the last run and the location of currect square not equeal to the dst there is illegal dst
		if (i == dstX && dstLoc.compare(arr[i][Y]->getLocation()))
		{
			ans = true;
		}
	}
	return ans;
}



/*The fucntion will check if the down row is free and there is no pieces in the way of the rook to the dst
input:
Pieces* arr[8][8], string dst, int startY, int dstY, int X
output:
true if there is something in the way that doesnt allow to move to the dst
false if the way is clear
*/
bool  Rook::down(Pieces* arr[8][8], string dst, int startX, int dstX, int Y)
{
	bool ans = false;
	string dstLoc = string() + dst[2] + dst[3];

	for (int i = startX+1; i <= dstX; i++)
	{
		//checkng if there is piece is the square
		if (arr[i][Y]->getTaken() && this != arr[i][Y])
		{
			//checking if there is something in the way and not in the dst
			if (i != dstX && arr[i][Y]->getSide()[0] != 'n')
			{
				ans = true;
				break;
			}
		}
		//if the for in the last run and the location of currect square not equeal to the dst there is illegal dst
		if (i == dstX && dstLoc.compare(arr[i][Y]->getLocation()))
		{
			ans = true;
		}
	}
	return ans;
}
