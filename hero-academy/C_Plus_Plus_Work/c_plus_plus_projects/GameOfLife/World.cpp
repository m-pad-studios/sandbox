#include "game_board_manager.hpp"
#include "conio.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>

using std::ofstream;

class World
{
public:

	void Menu()
	{
		char key = ' ';
		int num = 0;
		
		while (key != 'r' || 'w')
		{
			system("cls");
			cout << "WELCOME TO: JUMANJI!...uhhhh wait wrong game..." << endl;
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			cout << "Welcome to: The Game of Life" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Please select either Random World [r] or Create your own World [w]" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "If you get a random map that is not to your liking just hit [q] and it'll bring you back here to restart" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "For studying graph patterns mode hit [m] after a world has been seeded" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Hit [l] load an already saved graph" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			cin >> key;
			if (!isalpha(key))
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "PLEASE ENTER A LETTER...WHY DON'T YOU PESKY USERS EVER LISTEN *walks out of room*" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				GameBoardManager time;
				time.Timer(3000);
			}
			if (key == 'r')
			{
				RandomWorld();
			}
			if (key == 'w')
			{
				CreateWorld();
			}
			
		}
	}

	void CreateWorld()
	{	
		int H;
		int W;
		int w_cell;
		int v_cell;
		char key = ' ';
	
		while(isalnum(key))
			cout << "Please enter the dimensions of your World..." << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			cout << "Designated Height?" << endl;
			cin >> H;
		
			cout << "Height set to : " << H << endl;

			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Designated Width?" << endl;
			cin >> W;

			cout << "Width set to : " << W << endl;

			cout << endl;

			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Set number of White Blood Cells to defend : ";
			cin >> w_cell;

			cout << endl;

			cout << "Set number of Virus Cells to attack : ";
			cin >> v_cell;

			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			
			if (W && H >= 6 && H && W <= 200)
			{
				Board<char> board(W, H, w_cell, v_cell);

				GameBoardManager dealer(board);

				dealer.DealBoards(board);
			}
	}

	void RandomWorld()
	{
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<int> dis(6, 50); //adjust this from 6, 200 and it will spit out random grid inside those dimensions. niffty trick instead of the if statement above. itll never go out of bounds

		int w_cell;
		int v_cell;

		cout << "********************************" << endl;
		cout << "Random World chosen...good luck!" << endl;
		cout << "********************************" << endl;

		Board<char> board(dis(gen), dis(gen), dis(gen), dis(gen));

		GameBoardManager dealer(board);

		dealer.DealBoards(board);
	}

	/*void LoadWorld()
	{
		int H_L = 0;
		int W_L = 0;
		int w_cell_L = 0;
		int v_cell_L = 0;

		ifstream inFile;
		inFile.open("Graph0.txt");

		if (!inFile)
		{
			cout << "Unable to load file...doesn't exist" << endl;
			exit(3);
		}

		while (inFile >> H_L >> W_L >> w_cell_L >> v_cell_L)
		{
			H = H_L;
			W = W_L;
			w_cell = w_cell_L;
			v_cell = v_cell_L;

		}

		Board<char> board(H, W, w_cell, v_cell);
		GameBoardManager dealer(board);
		dealer.DealBoards(board);

		inFile.close();
	}*/

	bool GameControls(char* c)
	{
		if (_kbhit())
		{
			*c = _getch();
			return true; // Key Was Hit
		}
		return false; // No keys were pressed
	}
};