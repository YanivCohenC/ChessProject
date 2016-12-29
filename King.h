#pragma once
#include "Pieces.h"
#include "Rook.h"

class King : public Pieces
{
public:
	King(bool taken, string location, string type, string side);
	char move(Pieces* arr[8][8], string dst);
	bool checkUDLR(Pieces* arr[8][8], string dst);
	
private:
	bool squareCheck(Pieces* arr[8][8], string dst);
	bool check(Pieces* arr[8][8], string dst);
	

};