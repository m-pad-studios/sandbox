#ifndef bailer_HPP

#define bailer_HPP

#include "../DataStructures/hash_map.hpp"
#include "record.hpp"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

using std::vector;
using std::ofstream;
using std::function;
using namespace data_structures;

class Bailer
{
public:
	Bailer(const size_t& table_size, const function<int(const string & key)>& hash_function) : lyrics_(table_size, hash_function) {}
	void Compress(const string& filename);
	void Decompress(const string& filename);
	void PrintLyrics();

private:

	HashMap<string, vector<int>> lyrics_;
};
#endif