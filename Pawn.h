#pragma once

#include "Pieces.h"

class Pawn : public Pieces
{
public:
	Pawn(bool taken, string location, string type, string side);
	char move(Pieces* arr[8][8], string dst);

private:
	bool squareCheck(Pieces* arr[8][8], string dst);
};