#include "parser_utils.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using std::ifstream;
using std::string;
using std::ofstream;
using std::stringstream;
using std::endl;


vector<string> ParserUtils::GetAllLines(const string& filename)
{
	string line;
	vector<string> lines;

	ifstream file(filename);

	getline(file, line); //priming the loop
	lines.push_back(line);

		while (!file.eof())
		{
			getline(file, line);
			lines.push_back(line);
		}
	return lines;
}

void ParserUtils::WriteAllLines(const string filename, vector<string>& lines)
{
	ofstream file(filename);

	for (auto& line : lines)
	{
		file << line;
	}
}

vector<string> ParserUtils::Splits(const string& line, const char delimeter)
{
	vector<string> words;

	Split(line, delimeter, words);

	return words;
}

void ParserUtils::Split(const string& line, const char delimeter, vector<string>& words)
{
	stringstream stream(line);
	string word;

	while (getline(stream, word, delimeter))
	{
		words.push_back(word);
	}
}
