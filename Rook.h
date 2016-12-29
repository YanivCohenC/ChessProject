#pragma once
#include "Pieces.h"

class Rook : public Pieces
{
public:
	Rook( bool taken, string location, string type, string side);
	char move(Pieces* arr[8][8],string dst);
	
private:
	bool squareCheck(Pieces* arr[8][8], string dst);

	bool left(Pieces* arr[8][8], string dst, int startY, int dstY, int X);
	bool right(Pieces* arr[8][8], string dst, int startY, int dstY, int X);
	bool up(Pieces* arr[8][8], string dst, int startX, int dstX, int Y);
	bool down(Pieces* arr[8][8], string dst, int startX, int dstX, int Y);
};


