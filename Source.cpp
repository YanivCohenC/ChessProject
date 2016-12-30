#include "Pipe.h"
#include <iostream>
#include "Pieces.h"
#include "King.h"
#include "Empty.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include <thread>

using namespace std;
void main()
{
	srand(time_t(NULL));

	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	char board[] = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0";
	Pieces* arr[8][8];
	Pieces* Bking;
	Pieces* Wking;
	int x = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char chi = '8' - i;
			char chj = j + 'a';
			string s = { chj, chi };
			switch (board[x])
			{
			case 'r':
				arr[i][j] = new Rook(true, s, "rook", "Black");
				break;
			case 'n':
				arr[i][j] = new Knight(true, s, "knight", "Black");
				break;
			case 'b':
				arr[i][j] = new Bishop(true, s, "bishop", "Black");
				break;
			case 'k':
				arr[i][j] = new King(true, s, "King", "Black");
				Bking = arr[i][j];
				break;
			case 'q':
				arr[i][j] = new Queen(true, s, "queen", "Black");
				break;
			case 'p':
				arr[i][j] = new Pawn(true, s, "pawn", "Black");
				break;

			case 'R':
				arr[i][j] = new Rook(true, s, "rook", "White");
				break;
			case 'N':
				arr[i][j] = new Knight(true, s, "knight", "White");
				break;
			case 'B':
				arr[i][j] = new Bishop(true, s, "bishop", "White");
				break;
			case 'K':
				arr[i][j] = new King(true, s, "King", "White");
				//Wking = arr[i][j];
				break;
			case 'Q':
				arr[i][j] = new Queen(true, s, "queen", "White");
				break;
			case 'P':
				arr[i][j] = new Pawn(true, s, "pawn", "White");
				break;
			case '#':
				arr[i][j] = new Empty(false, s, "empty", "no");

				break;
			}
			x++;
		}

	}

	strcpy_s(msgToGraphics, board); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	int count = 0;
	while (msgFromGraphics != "quit")
	{
		string str;

		if (count % 2 == 0)
		{
			str = 'W';
		}
		else
		{
			str = 'B';
		}
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		int x = int(msgFromGraphics[0] - 'a');
		int x1 = int('8' - msgFromGraphics[1]);
		board[0] = arr[x1][x]->move(arr, msgFromGraphics + str);
		//while (1)
		//{
		//	Pieces* temp;
		//	int y = int(msgFromGraphics[2] - 'a');
		//	int y1 = int('8' - msgFromGraphics[3]);
		//	string strL = arr[y1][y]->getLocation();
		//	temp = arr[y1][y];
		//	arr[y1][y] = arr[x1][x];
		//	arr[x1][x] = temp;
		//	arr[x1][x]->setLocation(arr[y1][y]->getLocation());
		//	arr[y1][y]->setLocation(strL);
		//	if (Wking->move(arr, Wking->getLocation() + Wking->getLocation() + str) == '4')
		//	{
		//		board[0] = '4';
		//	}
		//	else if (Bking->move(arr, Bking->getLocation() + Bking->getLocation() + str) == '4')
		//	{
		//		board[0] = '4';
		//	}
		//	strL = arr[x1][x]->getLocation();
		//	temp = arr[x1][x];
		//	arr[x1][x] = arr[y1][y];
		//	arr[y1][y] = temp;
		//	arr[y1][y]->setLocation(arr[x1][x]->getLocation());
		//	arr[x1][x]->setLocation(strL);
		//	break;
		//}
		strcpy_s(msgToGraphics, board); // msgToGraphics should contain the result of the operation

		msgToGraphics[1] = 0;


		if (msgToGraphics[0] == '0' || msgToGraphics[0] == '1')
		{
			count++;
			Pieces* temp;
			int y = int(msgFromGraphics[2] - 'a');
			int y1 = int('8' - msgFromGraphics[3]);
			string strL = arr[y1][y]->getLocation();
			if (arr[y1][y]->getSide()[0] != 'n' && arr[x1][x]->getSide()[0] != 'n' && arr[x1][x]->getSide()[0] != arr[y1][y]->getSide()[0])
			{
				delete arr[y1][y];
				arr[y1][y] = new Empty(false, (to_string(msgFromGraphics[2]) + to_string(msgFromGraphics[3])), "Empty", "no");
			}
			temp = arr[y1][y];
			arr[y1][y] = arr[x1][x];
			arr[x1][x] = temp;
			arr[x1][x]->setLocation(arr[y1][y]->getLocation());
			arr[y1][y]->setLocation(strL);
		}
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

	}

	p.close();
}