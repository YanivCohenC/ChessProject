#pragma once
#include "Pieces.h"

class Rook : public Pieces
{
public:
	Rook( bool taken, string location, string type, string side);
	char move(Pieces* arr[8][8],string dst);
	
private:
	bool squareCheck(Pieces* arr[8][8], string dst);
};


