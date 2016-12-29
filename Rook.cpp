#include "Rook.h"


Rook::Rook(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char Rook::move(Pieces* arr[][8], string dst)
{
	char ans = '0';
	if (_taken != true || _side[0] != dst[4])
	{
		ans = '2';
	}
	else if (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken() && arr[int('8' - dst[3])][int(dst[2] - 'a')]->getSide()[0] == dst[4] && this->getLocation() != arr[int('8' - dst[3])][int(dst[2] - 'a')]->getLocation())
	{
		ans = '3';
	}
	else if ((dst[1] > '8' || dst[1] < '0') || (dst[3] > '8' || dst[3] < '0') || (dst[0] > 'h' || dst[0] < 'a') || (dst[2] > 'h' || dst[2] < 'a'))
	{
		ans = '5';
	}
	else if (squareCheck(arr, dst))
	{
		ans = '6';
	}
	else if (_location[0] == dst[2] && _location[1] == dst[3])
	{
		ans = '7';
	}
	return ans;
}


/*

*/
bool Rook::squareCheck(Pieces* arr[][8], string dst)
{
	bool ans = false;
	int x1 = int(dst[1] - '0'), x2 = int(dst[3] - '1'), y1 = int(dst[0] - 'a'), y2 = int(dst[2] - 'a');
	if (dst[0] == dst[2])
	{
		if (dst[1] < dst[3])
		{
			for (int i = x1; i<x2; i++)
			{
				if (arr[i][y1]->getTaken() && this != arr[i][y1])
				{
					if (arr[i][y1]->getSide()[0] == dst[4] && this->getSide() != arr[i][y1]->getSide() && arr[i][y1]->getSide()[0] != 'n' || arr[i][y1]->getSide()[0] != dst[4])
					{
						ans = true;
						break;
					}
				}
			}
		}
		else
		{
			for (int i =  8 - x1; i < 8 - x2; i++)
			{
				if (arr[i][y1]->getTaken())
				{
					if (arr[i][y1]->getSide()[0] == dst[4] && this->getLocation() != arr[i][y1]->getLocation() && arr[i][y1]->getSide()[0] != 'n' || arr[i][y1]->getSide()[0] != dst[4]&& (i + 1) != x1)
					{
						ans = true;
						break;
					}
				}
			}
		}
	}
	else if (dst[1] == dst[3])
	{
		if (dst[0] < dst[2])
		{
			for (int j = y1+1; j<y2; j++)
			{
				if (arr[8 - x1][j]->getTaken())
				{
					if (arr[x2][j]->getSide()[0] != dst[4] && arr[x2][j]->getSide()[0] != 'n' && arr[8 - x1][j]->getSide()[0] == dst[4])
					{

					}
					else
					{
						ans = true;
						break;
					}
				}
			}
		}
		else
		{
			for (int j = y2+1; j<y1; j++)
			{
				if (arr[8 - x1][j]->getTaken())
				{
					if (arr[x2][j]->getSide()[0] != dst[4] && arr[x2][j]->getSide()[0] != 'n' && arr[8 - x1][j]->getSide()[0] == dst[4])
					{

					}
					else
					{
						ans = true;
						break;
					}
				}
			}
		}
	}
	else
	{
		ans = true;
	}
	return ans;
}

