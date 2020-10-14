#ifndef virus_cell_HPP

#define virus_cell_HPP

#include "../DataStructures/array2d.hpp"
#include <iostream>

using namespace std;

using namespace data_structures;

class VirusCell
{
private:

	bool state_ = IsDead();
	const char v_cell_symbol = '%';
	

public:

	int cell_count;

	VirusCell() = default;
	
	VirusCell(int cell_count_)
	{
		cell_count = cell_count_;
		state_ = IsAlive();
	}

	char GetVirusCellCount()
	{
		return cell_count;
	}

	char VirusSymbol()
	{
		return v_cell_symbol;
	}

	bool IsAlive()
	{
		return true;
	}

	bool IsDead()
	{
		return false;
	}

	void SetState()
	{
		if (IsAlive())
		{
			state_ = true;
		}
		else
		{
			state_ = IsDead();
		}
	}
};


#endif