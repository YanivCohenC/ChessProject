#pragma once
#include "Pieces.h"


class Bishop : public Pieces
{
public:
	Bishop(bool taken, string location, string type, string side);
	char move(Pieces* arr[8][8], string dst);

private:
	bool squareCheck(Pieces* arr[8][8], string dst);

	bool upLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY);
	bool upRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY);
	bool downLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY);
	bool downRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstX, int dstY);
};




#pragma endregion