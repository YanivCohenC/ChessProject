#pragma once
#include <string>
#include <iostream>

using namespace std;


class Pieces
{
protected:
	bool _taken;
	string _location;
	string _type;
	string _side;

public:
	Pieces(bool taken, string location, string type, string side);
	virtual char move(Pieces* arr[8][8],string dst) = 0;
	virtual bool squareCheck(Pieces* arr[8][8], string dst) = 0;
	bool getTaken();
	string getSide();
	void setLocation(string str);
	string getLocation();
	string getType();

};
#pragma endregion