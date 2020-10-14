#ifndef PARSER_UTILS_HPP
#define PARSER_UTILS_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

class ParserUtils
{
public:
	
	static vector<string> GetAllLines(const string& filename);
	static void WriteAllLines(const string filename, vector<string>& lines);
	static vector<string> Splits(const string& line, const char delimeter);

private:

	static void Split(const string& line, const char delimeter, vector<string>& words);

};
#endif // !PARSER_UTILS_HPP
