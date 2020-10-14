#include <iostream>
#include <crtdbg.h>
#include "RecordStore.cpp"

#define _CRTDBG_MAP_ALLOC

using std::cout;
using std::endl;


int main()
{
	{
		RecordStore mpad_studios;
		mpad_studios.Menu();
		
	}


	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
}

