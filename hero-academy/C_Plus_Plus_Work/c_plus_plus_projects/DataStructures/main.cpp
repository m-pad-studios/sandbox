#include <iostream>
#include <crtdbg.h>

#include "driver.hpp"
#include "linked_list.hpp"


#define _CRTDBG_MAP_ALLOC

using std::cout;
using std::endl;

using namespace data_structures;

int main()
{
	{
	
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
}

