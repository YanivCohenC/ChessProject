#include "Pawn.h"


Pawn::Pawn(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char Pawn::move(Pieces* arr[][8], string dst)
{
	char ans = '0';
	if (_taken != true || _side[0] != dst[4])
	{
		ans = '2';
	}
	else if (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken() && this != arr[int('8' - dst[3])][int(dst[2] - 'a')] && _side[0] == arr[int('8' - dst[3])][int(dst[2] - 'a')]->getSide()[0])
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
bool Pawn::squareCheck(Pieces* arr[][8], string dst)
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