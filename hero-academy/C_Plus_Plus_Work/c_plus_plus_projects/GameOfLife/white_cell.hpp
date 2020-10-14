#ifndef white_blood_cell_HPP

#define white_blood_cell_HPP

#include "../DataStructures/array2d.hpp"
#include <iostream>

using namespace std;
using namespace data_structures;

class WhiteBloodCell
{
private:

	bool state_ = IsDead();
	
	const char w_cell_symbol = '@';

public:

	int cell_count;

	WhiteBloodCell() = default;

	WhiteBloodCell(int cell_count_)
	{
		cell_count = cell_count_;
		state_ = IsAlive();
	}

	char WhiteBloodCellCount()
	{
		return cell_count;
	}

	char WhiteBloodCellSymbol()
	{
		return w_cell_symbol;
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