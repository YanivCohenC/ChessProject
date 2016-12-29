#pragma once
#include "Pieces.h"
#include "Rook.h"

class King : public Pieces
{
public:
	King(bool taken, string location, string type, string side);
	char move(Pieces* arr[8][8], string dst);
	bool check(Pieces* arr[8][8], string dst);
	
private:
	bool squareCheck(Pieces* arr[8][8], string dst);

	bool rookCheck(Pieces* arr[8][8], string dst);
	bool left(Pieces* arr[8][8], string dst, int startY, int dstY, int X);
	bool right(Pieces* arr[8][8], string dst, int startY, int dstY, int X);
	bool up(Pieces* arr[8][8], string dst, int startX, int dstX, int Y);
	bool down(Pieces* arr[8][8], string dst, int startX, int dstX, int Y);

	bool bishopCheck(Pieces* arr[8][8], string dst);
	bool upLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstY);
	bool upRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstY);
	bool downLeft(Pieces* arr[8][8], string dst, int startX, int startY, int dstY);
	bool downRight(Pieces* arr[8][8], string dst, int startX, int startY, int dstY);

	bool knightCheck(Pieces* arr[8][8], string dst);

	bool pawnCheck(Pieces* arr[8][8], string dst);
	
};