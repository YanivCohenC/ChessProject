#include "Empty.h"

Empty::Empty(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char Empty::move(Pieces* arr[8][8], string dst)
{
	return '2';
}


/*

*/
bool Empty::squareCheck(Pieces* arr[8][8], string dst)
{
	return false;
}
