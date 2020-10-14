#include "bailer.hpp"
#include "conio.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "record.hpp"


using std::ofstream;

class RecordStore
{
private:
	vector<pair<int, string>> records_;
	long cash_money_in_da_bank = 10000;
	bool flag = true;
	

public:

	void Menu()
	{
		RecordFactory();
		string filename;
		char key = ' ';
		int num = 0;

		const size_t kTableSize = 123;
		auto hash_function = [&](const string& key) -> int
		{
			int sum{};
			for (auto& ch : key)
			{
				sum += static_cast<int>(ch);
			}
			return sum % kTableSize;
		};

		Bailer bailer(kTableSize, hash_function);

		while (key != 'q')
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "		Welcome to: M-PAD STUDIOS!" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~~~~~~~~~ CURRENT CASH MONEY IN DA BANK ~~~~~~~~~~~~" << endl;
			cout << "-------------------> $" << cash_money_in_da_bank << " <--------------" << endl;
			cout << "Please select a file to compress a file of lyrics [c]" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Display the lyrics of the compressed file [l] CANT DISPLAY WITHOUT COMPRESSING FIRST" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Please load a file to decompress [d] " << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "To create a record to store in the Juke Box press [r] ex: Record Number: 1 Record Name: Indestructible by Disturbed" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "To access the stores Juke Box press [j] while in the Juke Box press 1 to display a list of all the songs" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "SECRET --- Mike's favorite Foreigner song ---> PRESS THIS LAST TO CLOSE UP SHOP -- > [m]" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			cin >> key;
			if (!isalpha(key))
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "PLEASE ENTER A LETTER...WHY DON'T YOU PESKY USERS EVER LISTEN *walks out of room*" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			if (key == 'c')
			{
				cash_money_in_da_bank += 1000;
				cout << "Enter a record name to compress: " << endl;
				cin >> filename;
				if (filename != " ")
				{
					cout << "< . . . A FEW MOMENTS WHILE THE BAILER COLD BREW PRESSES YOUR FILE . . . >" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					bailer.Compress(filename);
					
				}
			}
			if (key == 'r')
			{
			
					flag = false;
					cash_money_in_da_bank += 1000;
					auto upc = 0;
					string title;

					cout << "Record Number : " << endl;
					cin >> upc;

					cout << "Record Label : " << endl;
					cin >> title;

					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << " |m| ROCK ON! RECORD CREATED IN THE JUKE BOX! |m|" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

					records_.push_back(std::make_pair(upc, title));
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			}
			if (key == 'j')
			{
				int upc = 0;
				cash_money_in_da_bank += 1000;
				cout << "~~~ WELCOME TO THE M-PAD STUDIOS JUKE BOX HERO~~~" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "~~~ PLEASE ENTER A NUMBER TO LOOK UP YOUR RECORD ~~~" << endl;

				cin >> upc;
				ChooseRecordFromJukeBox(upc);
			}

			if (key == 'l')
			{
				cash_money_in_da_bank += 1000;
				bailer.PrintLyrics();
			}

			if (key == 'd')
			{
				cash_money_in_da_bank += 1000;
				cout << "Enter a record name to decompress to: " << endl;
				cin >> filename;
				if (filename != " ")
				{
					cout << "< . . . A FEW MOMENTS WHILE THE BAILER WHIPS UP A PUMPKIN SPICE LATE FOR YOU . . . >" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					bailer.Decompress(filename);

				}
			}
			if (key == 'm')
			{
				cash_money_in_da_bank = 1000000;
				Record<int, string> mikes_record(4,"4");
	
				mikes_record.setArtist("Foreigner");
				mikes_record.setSongCount(12);

				string song = " So he started rockin' \n Ain't never gonna stop \n Gotta keep on rockin' \n Someday he's gonna make it to the top \n And be a juke box hero, got stars in his eyes \n He's a juke box hero \n He took one guitar, juke box hero, stars in his eyes \n Juke box hero, he'll come alive tonight";
				mikes_record.AddSong(song);
				mikes_record.PrintRecordInfo();
				mikes_record.DisplayLyrics(0);
				
				if (cash_money_in_da_bank == 1000000)
				{
					cout << "!!!YOUS A MILLIONAIRE!!!" << endl;
					cout << "$$$ " << cash_money_in_da_bank << " $$$" << endl;
					exit(3);
				}
			}

		}
	}

	void ChooseRecordFromJukeBox(int upc)
	{
		
		if (upc == 0)
		{
			cout << "RECORD DOESN'T EXIST" << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
		else if(upc == 1)
		{
			for (auto& key : records_)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "RECORD NUMBER" << " | " << "TITLE" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << key.first << ". ";
				cout << "		" << key.second;
			}
			cout << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}

	}

	void RecordFactory()
	{
		records_.push_back(std::make_pair(1, "Juke Box Hero by Foreigner"));
		records_.push_back(std::make_pair(2, "Carry On Wayward Son by Kansas"));
		records_.push_back(std::make_pair(3, "Hotel California by Eagles"));
		records_.push_back(std::make_pair(4, "Wheel In The Sky by Journey"));
		records_.push_back(std::make_pair(5, "Dont Stop Believing by Journey"));
		records_.push_back(std::make_pair(6, "Billy Jean by Michael Jackson"));
		records_.push_back(std::make_pair(7, "TLC by Michael Jackson"));
		records_.push_back(std::make_pair(8, "They Don't Care About Us by Michael Jackson"));
		records_.push_back(std::make_pair(9, "Say Something by Justin Timberlake"));
		records_.push_back(std::make_pair(10, "Mirrors by Justin Timberlake"));
	}
};