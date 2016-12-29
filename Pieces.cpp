#include "Pieces.h"

Pieces::Pieces(bool taken, string location, string type, string side)
{
	_taken = taken;
	_location = location;
	_type = type;
	_side = side;
}

bool Pieces::getTaken()
{
	return _taken;
}

string Pieces::getLocation()
{
	return _location;
}

string Pieces::getSide()
{
	return _side;
}

string Pieces::getType()
{
	return _type;
}

void Pieces::setLocation(string str)
{
	_location = str;
}