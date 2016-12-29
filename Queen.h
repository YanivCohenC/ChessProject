#pragma once
#include "Pieces.h"
#include "Rook.h"
#include "Bishop.h"


class Queen : public Pieces
{
public:
	Queen(bool taken, string location, string type, string side);
	char move(Pieces* arr[8][8], string dst);

private:
	bool squareCheck(Pieces* arr[8][8], string dst);

};