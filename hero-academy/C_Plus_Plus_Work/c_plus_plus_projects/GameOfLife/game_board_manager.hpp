#ifndef game_board_manager_HPP

#define game_board_manager_HPP

#include "../DataStructures/array2d.hpp"
#include <iostream>
#include "conio.h"
#include "board.hpp"
#include <chrono>
#include <thread>
#include <fstream>

using std::ofstream;

using namespace std;

using namespace data_structures;

class GameBoardManager
{

private:

	WhiteBloodCell w;
	VirusCell v;
	int plus_time = 5000;
	bool flag = false;

public:

	GameBoardManager() = default;

	GameBoardManager(Board<char> board_)
	{
		Board<char> board_main = board_;
	}
	/*
	~~~Simple function to display the board~~~
	*/
	void DealBoards(Board<char> board_)
	{
		if (w.cell_count && v.cell_count != 0)
		{
			cout << "**************************************" << endl;
			cout << "*CELLS HAVE BEEN SPAWNED....GOOD LUCK!*" << endl;
			cout << "**************************************" << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		}
	
		char key = ' ';
		while (key != 'q')
		{
			system("CLS");

			while (!GameControls(&key))
			{
				if (key == 'p')
				{
					board_.DisplayBoard();
					system("PAUSE");
				}

				if (key == 'm')
				{
					board_.DisplayBoard();
					board_.NextState();
					Timer(plus_time);
					break;
				}

				if (key == 's')
				{
					string file = "Graph" + to_string(board_.GraphNum());
					string file_merged = file + ".txt";
					board_.StoreBoardTxtFile(file_merged);
					//this does actually pop up lol...it gets lost in the stream of life
					cout << "Graph Saved!" << endl;
				}

				if (key == '+')
				{
					if (flag == true)
					{
						cout << "SPEED OF WORLD ADJUSTING, JUST ONE MOMENT PLEASE :D..." << endl;
						Timer(3000);
					}
					plus_time += 1000;
					flag = false;
				}

				if (key == '-')
				{
					if (flag == false)
					{
						cout << "SPEED OF WORLD ADJUSTING, JUST ONE MOMENT PLEASE :D..." << endl;
						Timer(3000);
					}
					flag = true;
					plus_time = 0;
				}

				board_.BoardWithBoarder();
				board_.DisplayBoard();
				board_.NextState();
				board_.DisplayBoard();
				
				Timer(plus_time);
			}
			// Update Program Logic Here
			cout << "You Pressed: " << key << endl;
		}
	}
	
	/* RECYCLED METHODS SECTION */
	void Timer(int ms)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	bool GameControls(char* c)
	{
		if (_kbhit())
		{
			*c = _getch();
			return true; // Key Was Hit
		}
		return false; // No keys were pressed
	}
	/* END RECYCLED METHODS SECTION*/
};
#endif