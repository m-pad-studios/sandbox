#ifndef record_HPP

#define record_HPP

#include "../DataStructures/pair.hpp"
#include "../DataStructures/array.hpp"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <thread>

using namespace std;
using std::ofstream;
using namespace data_structures;

template <class F, class S>
class Record : Pair<int, string>
{
private:

	int upc;
	int song_count =  0;
	string title;
	string artist;
	string lyrics;
	Array<string> songs;
	
public:

	Record() = default;

	Record(int upc_, string title_) : upc(upc_), title(title_)
	{
		artist = ' ';
	}

	void DisplayLyrics(int song)
	{
		int counter = 0;

		if (song > songs.Length())
		{
			throw AdtException("Can't ask for a song that doesn't exist...");
		}
		
		
		for (auto i = 0u; i < songs.Length(); ++i)
		{
			for (char lyric : songs[song])
			{
				counter += 1;

				if (lyric = lyric && counter <= 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << "***********************" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					cout << songs[song] << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << "***********************" << endl;
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	}

	void AddSong(string lyrics)
	{
		
		for (auto i = 0u; i < songs.Length(); ++i)
		{
		 songs[i] = lyrics;
		}
	}

	void PrintRecordInfo()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "********************************" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "*Record number : " << GetUPC() <<endl;
		cout << "*Title of record : " << GetTitle() << endl;
		cout << "*Number of songs : " << GetSongCount() << endl;
		cout << "*Artist of record : " << GetArtist() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "********************************" << endl;

	}
	/*GETTERS & SETTERS SECTION*/
	int GetUPC()
	{
		return upc;
	}

	int GetSongCount()
	{
		return song_count;
	}

	string GetTitle()
	{
		return title;
	}

	string GetArtist()
	{
		return artist;
	}

	void setUPC(int& upc_)
	{
		upc = std::move(upc_);
	}

	void setTitle(string title_)
	{
		title = title_;
	}

	void setArtist(string artist_)
	{
		artist = artist_;
	}

	void setSongCount(int song_count_)
	{
		song_count = song_count_;
		songs = Array<string>(song_count);
	}
	/*END GETTER & SETTER SECTION*/
};
#endif