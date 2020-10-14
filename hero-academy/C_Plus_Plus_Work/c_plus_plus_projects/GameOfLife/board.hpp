#ifndef board_HPP

#define board_HPP

#include "../DataStructures/array2d.hpp"
#include <iostream>
#include <windows.h>
#include <random>
#include "white_cell.hpp"
#include "virus_cell.hpp"
#include <fstream>
#include <thread>
using namespace std;
using std::ofstream;
using namespace data_structures;

template <class T>
class Board : Array2D<T> 

{
	private:

	int dayCounter = 0;
	int height_ = 0;
	int width_ = 0;
	int w_cell = 0;
	int v_cell = 0;
	int graph_num = 0;

	const char boarder = '*';
	const char neutral_symbol = '~';

	bool warning_flag = false;

	Array2D<char> board_;
	WhiteBloodCell white_B_Cell;
	VirusCell virus_Cell;
	
public:

	Board() = default;

	Board(int width, int height, int w_cell, int v_cell)
	{
			height_ = height;
			width_ = width;

			board_ = Array2D<char>(height_, width_);

			WhiteBloodCell white_B_Cell(w_cell);
			VirusCell virus_cell(w_cell);
	}
	
	/*
~~~SECTION FOR DIFFERENT STYLE OF BOARDS~~~
If developer chooses to create a different style of board.
He/Her would just create a new method here and it will change the boards style.
Example use: A board that is cut in half, a small board that displays state data
*/
	void BoardWithBoarder()
	{
		int _i = board_.Rows();
		int _j = board_.Columns();
	
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<int> dis(1,5);

		for (int i = 0; i < _i; i++) {
			for (int j = 0; j < _j; j++) {
				if (i == 0 || j == 0 || i == _i - 1 || j == _j - 1) {
					board_[i][j] = boarder;
				}
				else
				{
					//This setup is part 1 of the Factorio Sweeping Algorithm

					 if (i == dis(gen) || j == dis(gen))
					{
					board_[i][j] = white_B_Cell.WhiteBloodCellSymbol();
					}
					
					else if (i == dis(gen) || j == dis(gen))
					{

					board_[i][j] = virus_Cell.VirusSymbol();
					}
			
					else if (i < 0 || j < 0 || i > board_.Rows() - 1 || j > board_.Columns() - 1 || board_.Select(dis(gen), j) == white_B_Cell.WhiteBloodCellSymbol())
					{

					board_[i][j] = white_B_Cell.WhiteBloodCellSymbol();
					}

					else if(white_B_Cell.WhiteBloodCellCount() > virus_Cell.GetVirusCellCount() && i < 0 || j < 0 || i > board_.Rows() - 1 || j > board_.Columns() - 1 || board_.Select(dis(gen), j) == white_B_Cell.WhiteBloodCellSymbol())
					 {

						 board_[i][j] = virus_Cell.VirusSymbol();
					 }

					else
					{
					board_[i][j] = neutral_symbol;
					}
				}
			}
		}
	}

	void DisplayBoard()
	{

		cout << std::string("DAY ") << dayCounter << std::string("...") << endl;
		dayCounter++;

		cout << std::string("WHITE BLOOD CELL COUNT : ") << w_cell << endl;
		cout << endl;

		cout << std::string("VIRUS CELL COUNT : ") << v_cell << endl;

		w_cell = 0;
		v_cell = 0;

		for (int r = 0; r < board_.Rows(); r++)
		{
			for (int c = 0; c < board_.Columns(); c++)
			{
				if (board_[r][c] == white_B_Cell.WhiteBloodCellSymbol())
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << board_[r][c];
					w_cell++;
				}
				if (board_[r][c] == virus_Cell.VirusSymbol())
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << board_[r][c];
					v_cell++;
				}
				if(board_[r][c] == boarder)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					cout << board_[r][c];
				}
				else if (board_[r][c] == neutral_symbol)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					cout << board_[r][c];
				}
			
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << endl;

		if (w_cell == 0 || v_cell == 0)
		{
			string file = "Graph" + to_string(graph_num);
			string file_merged = file + ".txt";

			cout << "*************************************" << endl;
			cout << "DAY : " << dayCounter << endl;
			cout << "STABILITY REACHED AT GRID DIMENSIONS " << endl; 
			cout << "HEIGHT: " << board_.Rows() << endl;
			cout << "WIDTH: " << board_.Columns() << endl;
			cout << "*************************************" << endl;
			cout << "*VIRUS : " << v_cell << "    *" << endl;
			cout << "*************************************" << endl;
			cout << "*************************************" << endl;
			cout << "*WHITE BLOOD CELLS : " << w_cell << "	    *" << endl;
			cout << "*************************************" << endl;
			StoreBoardTxtFile(file_merged);

			for (int r = 0; r < board_.Rows(); r++)
			{
				for (int c = 0; c < board_.Columns(); c++)
				{
					board_[r][c] = white_B_Cell.WhiteBloodCellSymbol();	
				}
			}
			exit(3);
		}
		if (v_cell > w_cell)
		{
			VirusOutBreak();
		}
	}


	void NextState()
	{
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<int> dis(1, 5);

		for (int r = 0; r < board_.Rows(); r++)
		{
			for (int c = 0; c < board_.Columns(); c++)
			{
				if (r == 0 || c == 0 || r == board_.Rows() - 1 || c == board_.Columns() - 1) {
					board_[r][c] = boarder;
				}

				//RULE SECTION...this is the logic to end the simulation
				//This setup is part 2 of the Factorio Sweeping Algorithm
				else if (v_cell > w_cell)
				{
					
					if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(dis(gen), dis(gen)) == white_B_Cell.WhiteBloodCellSymbol() || neutral_symbol)
					{
						board_[r][c] = virus_Cell.VirusSymbol();
					}

				}

				else if (dayCounter > 1000)
				{

					if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(dis(gen), dis(gen)) == virus_Cell.VirusSymbol() || neutral_symbol)
					{
						board_[r][c] = white_B_Cell.WhiteBloodCellSymbol();
					}

				}
					/*WIN CONDITIONS */	

				else if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(dis(gen), c) == virus_Cell.VirusSymbol()) //rule 1
				{
			
					board_[r][c] = white_B_Cell.WhiteBloodCellSymbol();
				}
				else if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(r ,dis(gen)) == virus_Cell.VirusSymbol()) //rule 1
				{

					board_[r][c] = white_B_Cell.WhiteBloodCellSymbol();
				}
				else if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(r, dis(gen)) == white_B_Cell.WhiteBloodCellSymbol())
				{
						board_[r][c] = virus_Cell.VirusSymbol();	
				}
				else if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(dis(gen), c) == white_B_Cell.WhiteBloodCellSymbol()) //rule 1
				{

					board_[r][c] = virus_Cell.VirusSymbol();
				}
				else if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(r, dis(gen)) == white_B_Cell.WhiteBloodCellSymbol()) //rule 1
				{

					board_[r][c] = virus_Cell.VirusSymbol();
					w_cell--;
				}
				else if (r < 0 || c < 0 || r > board_.Rows() - 1 || c > board_.Columns() - 1 || board_.Select(r, dis(gen)) == white_B_Cell.WhiteBloodCellSymbol()) //rule 1
				{

					board_[r][c] = virus_Cell.VirusSymbol();
				}

				//END OF RULE SECTION
			}
		}
	}
	void SwitchBoard(Board<char> board)
	{

		for (int r = 0; r < board_.Rows(); r++)
		{
			for (int c = 0; c < board_.Columns(); c++)
			{
				board_[r][c] = board[r][c];
			}
		}

	}

	void StoreBoardTxtFile(string file)
	{
		ofstream fout;
		
		fout.open(file);
		fout << std::string("DAY ") << dayCounter << std::string("...") << endl;
		fout << "HEIGHT: " << Rows() << endl;
		fout << "WIDTH: " << Cols() << endl;
		fout << "STABILITY REACHED FOR WHITE BLOOD CELLS : " << w_cell << endl;
		fout << "STABILITY REACH FOR VIRUS CELLS : " << v_cell << endl;
		for (int r = 0; r < board_.Rows(); r++)
		{
			for (int c = 0; c < board_.Columns(); c++)
			{
			fout <<	board_[r][c];
			}
			fout << endl;
		}
		fout << endl;
		graph_num++;
		fout.close();
	}

	/*OUT BREAK METHODS*/
	void VirusOutBreak()
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "! EMERGENCY VIRUS OUTBREAK !" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		warning_flag = true;
	}
	/*END OF SECTION*/

	/*
	GETTER METHODS PURELY FOR TESTS:::IS NOT NEEDED TO RUN PROGRAM
	IF I WERE TO LAUNCH FOR PRODUCTION THIS SECTION WOULD BE REMOVED
	*/
	int GraphNum()
	{
		return graph_num;
	}

	int WCell()
	{
		return w_cell;
	}

	int VCell()
	{
		return v_cell;
	}
	int Cols()
	{
		return board_.Columns();
	}

	int Rows()
	{
		return board_.Rows();
	}
};
#endif