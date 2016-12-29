#include "King.h"

King::King(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char King::move(Pieces* arr[8][8], string dst)
{
	char ans = '0';
	if (_taken != true || _side[0] != dst[4])
	{
		ans = '2';
	}
	else if (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken() && this != arr[int('8' - dst[3])][int(dst[2] - 'a')] && _side[0] == arr[int('8' - dst[3])][int(dst[2] - 'a')]->getSide()[0])
	{
		ans = '3';
	}
	//else if (check(arr, dst))
	//{
	//	ans = '4';
	//}
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


bool King::check(Pieces* arr[8][8], string dst)
{
	bool ans = true;
	string side = { dst[4] };
	string loc = { dst[0], dst[1] };
	string dst1 = { dst[2], dst[1], dst[2], '1', dst[4] };
	ans = this->checkUDLR(arr, dst1);
	if (!ans)
	{
		dst1 = { dst[2], dst[1], dst[2], '8', dst[4] };
		ans = this->checkUDLR(arr, dst1);
		if (!ans)
		{
			dst1 = { dst[0], dst[3], 'h', dst[3], dst[4] };
			ans = this->checkUDLR(arr, dst1);
			if (!ans)
			{
				dst1 = { dst[0], dst[3], 'a', dst[3], dst[4] };
				ans = this->checkUDLR(arr, dst1);
				if (!ans)
				{
					ans = false;
				}
			}
		}
	}
	return ans;
}

bool King::checkUDLR(Pieces* arr[8][8], string dst)
{
	bool ans = false;
	int x1 = int(dst[1] - '0'), x2 = int(dst[3] - '1'), y1 = int(dst[0] - 'a'), y2 = int(dst[2] - 'a');
	if (dst[0] == dst[2])
	{
		if (dst[1] < dst[3])
		{
			for (int i = 0; i<x2; i++)
			{
				if (arr[i][y1]->getSide()[0] == dst[4] && this != arr[i][y1])
				{
					break;
				}
				else if (arr[i][y1]->getTaken() && this != arr[i][y1])
				{
					if (this != arr[i][y1] && arr[i][y1]->getSide()[0] != 'n' && arr[i][y1]->getSide()[0] != dst[4])
					{
						ans = true;
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 8 - x1; i < 8; i++)
			{
				if (arr[i][y1]->getSide()[0] == dst[4] && this != arr[i][y1])
				{
					break;
				}
				else if (arr[i][y1]->getTaken())
				{
					if (this != arr[i][y1] && arr[i][y1]->getSide()[0] != 'n' && arr[i][y1]->getSide()[0] != dst[4])
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
			for (int j = y1; j<y2+1; j++)
			{
				if (arr[8 - x1][j]->getTaken())
				{
					if (arr[8 - x1][j]->getSide()[0] == dst[4] && this != arr[8 - x1][j])
					{
						break;
					}
					else if (arr[8 - x1][j]->getSide()[0] != dst[4] && arr[8 - x1][j]->getSide()[0] != 'n')
					{
						ans = true;
						break;
					}
				}
			}
		}
		else
		{
			for (int j = y1; j>=0; j--)
			{
				if (arr[8 - x1][j]->getTaken())
				{
					if (arr[8 - x1][j]->getSide()[0] == dst[4] && this != arr[8 - x1][j])
					{
						break;
					}
					else if (arr[8 - x1][j]->getSide()[0] != dst[4] && arr[8 - x1][j]->getSide()[0] != 'n')
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

/*

*/
bool King::squareCheck(Pieces* arr[8][8], string dst)
{
	bool ans = true;
	int x = ('8' - dst[3]), y = (dst[2] - 'a');

	// THIS WORKS WELL
	if (dst[0] == dst[2] && (dst[1] + 1 == dst[3] || dst[1] - 1 == dst[3])) // Up or down check
	{
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	// THIS WORKS WELL
	else if (dst[1] == dst[3] && (dst[0] + 1 == dst[2] || dst[0] - 1 == dst[2])) // Left or right check
	{
		char ch = arr[x][y]->getSide()[0];
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	// THIS NEEDS FIXING
	else if ((dst[0] == dst[2] + 1 && dst[1] == dst[3] + 1) || (dst[1] == dst[3] - 1 && dst[2] == dst[0] - 1)) // Upper right or lower left check
	{
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	// THIS NEEDS FIXING
	else if ((dst[0] == dst[2] - 1 && dst[1] == dst[3] - 1) || (dst[1] == dst[3] + 1 && dst[2] == dst[0] + 1)) // Upper left or lower right check
	{
		if (!(arr[x][y]->getTaken()) || (arr[x][y]->getTaken() && arr[x][y]->getSide()[0] != dst[4]))
		{
			ans = false;
		}
	}

	return ans;
}

