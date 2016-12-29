#include "Queen.h"

Queen::Queen(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}


char Queen::move(Pieces* arr[][8], string dst)
{
	char ans = '0';
	if (_taken != true || _side[0] != dst[4])
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


bool Queen::squareCheck(Pieces* arr[][8], string dst)
{
	Pieces* rookMove = new Rook(false, this->getLocation(), "rook", this->getSide());
	Pieces* bishopMove = new Bishop(false, this->getLocation(), "rook", this->getSide());
	bool ans = false;

	if (rookMove->move(arr, dst) != '0' && bishopMove->move(arr, dst) != '0')
	{
		ans = true;
	}
	return ans;
}
