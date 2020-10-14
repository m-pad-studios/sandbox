#include "bailer.hpp"
#include "parser_utils.hpp"


void Bailer::Compress(const string& filename)
{
	vector<string> lines = ParserUtils::GetAllLines(filename);
	size_t word_position = 0;
const auto vector_creation_function = []() -> vector<int> {
				return vector<int>();
			};

	for (auto& line : lines)
	{
		vector<string> words = ParserUtils::Splits(line, ' ');

		if (words.empty())
		{
			lyrics_.GetOrAdd(string ("\n"), vector_creation_function).push_back(word_position++);
			continue;
		}

		for (size_t i = 0; i < words.size(); ++i)
		{
			auto factor = i == words.size() - 1 ? -1 : 1;

		lyrics_.GetOrAdd(words[i], vector_creation_function).push_back(word_position++ * factor);
		}
	}
	
}

void Bailer::Decompress(const string& filename)
{
	vector<string> lines;

	auto number_of_words = 0u;

	const auto count_visit_function = [&](const string& key, const vector<int>& value)
	{
		number_of_words += value.size();
	};

	lyrics_.Traverse(count_visit_function);

	vector<string> words(number_of_words);

	const auto words_visit_function = [&](const string& word, const vector<int>& positions)
	{
		for (auto& position : positions)
		{
			words[abs(position)] = word;
			if (position < 0)
			{
				words[abs(position)] = words[abs(position)] + '\n';
			}
		}
	};

	lyrics_.Traverse(words_visit_function);

	auto line = string("");

	for (auto& word : words)
	{
		if (word.find('\n', 0) != string::npos)
		{
			line += word;
			lines.push_back(line);
			line = "";
		}
		else
		{
			line += word + " ";
		}
	}
	ParserUtils::WriteAllLines(filename, lines);
}

void Bailer::PrintLyrics()
{
	if (lyrics_.Count() == 0) { throw AdtException("No lyrics in the bailer :'("); }
	int counter = 0;
	vector<int> values1;
	vector<string> keys;

	const auto visit_function = [&](const string& key, vector<int> values2) -> void
	{
		cout << key << " : ";
		for (auto& position : values2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << position << " ";
		}
		cout << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	};
	lyrics_.Traverse(visit_function);
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}
