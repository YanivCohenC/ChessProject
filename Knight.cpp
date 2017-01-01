#include "Knight.h"


Knight::Knight(bool taken, string location, string type, string side) : Pieces(taken, location, type, side) // CTOR of knight
{
	// Inherits from Pieces, and uses its values (istaken, location, time and side)
}

char Knight::move(Pieces* arr[][8], string dst) // Main Knight move function
{
	char ans = '0'; // This is the ans - 0 stands for valid move
	if (_taken != true || _side[0] != dst[4]) // 2 stands for if the source tile has a piece that is the current side's turn so the user will only play on his turn
	{
		ans = '2';
	}
	else if (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken() && this != arr[int('8' - dst[3])][int(dst[2] - 'a')] && _side[0] == arr[int('8' - dst[3])][int(dst[2] - 'a')]->getSide()[0])
	{
		ans = '3'; // 3 stands for if the destination is taken and has a piece from the opposite side
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
bool Knight::squareCheck(Pieces* arr[][8], string dst)
{
	bool ans = false;
	int y1 = int(dst[1] - '0'), y2 = int(dst[3] - '0'), x1 = int(dst[0] - 'a') + 1, x2 = int(dst[2] - 'a') + 1;

	if ((x1 == x2 - 1 && y1 == y2 - 2)/* < UP RIGHT */ || (x1 == x2 + 1 && y1 == y2 - 2)/* < UP LEFT */)
	{
		return ans;
	}

	if ((x1 == x2 - 2 && y1 == y2 - 1)/* < RIGHT UP */ || (x1 == x2 - 2 && y1 == y2 + 1)/* < RIGHT DOWN */)
	{
		return ans;
	}

	if ((x1 == x2 - 1 && y1 == y2 + 2)/* < DOWN RIGHT */ || (x1 == x2 + 1 && y1 == y2 + 2)/* < DOWN LEFT */)
	{
		return ans;
	}

	if ((x1 == x2 + 2 && y1 == y2 - 1)/* < LEFT UP */ || (x1 == x2 + 2 && y1 == y2 + 1)/* < LEFT DOWN */)
	{
		return ans;
	}

	ans = true;
	return ans;
}
