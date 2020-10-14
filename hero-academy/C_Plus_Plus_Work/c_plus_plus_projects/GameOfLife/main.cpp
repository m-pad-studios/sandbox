#include <iostream>
#include <crtdbg.h>
#include "board.hpp"
#include <driver.hpp>
#include <linked_list.hpp>
#include "game_board_manager.hpp"
#include "World.cpp"

#define _CRTDBG_MAP_ALLOC

using std::cout;
using std::endl;


int main()
{
	{
		World earth;
		earth.Menu();
	}


	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
}

