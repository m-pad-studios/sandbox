#include <crtdbg.h>
#include "Sorter.cpp"

#define _CRTDBG_MAP_ALLOC

int main()
{
	{
		

	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
}
	

