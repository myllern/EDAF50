#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"
#include "sstream"
#include <algorithm>

using std::string;
using std::stringstream;
using std::unordered_set;
using std::vector;
using namespace std;

Dictionary::Dictionary()
{

	ifstream infile("new.txt");
	string newword;
	string newline;
	string temp;
	vector<string> triograms;
	int newwordLength;

	while (getline(infile, newline))
	{
		stringstream ss(newline);
		newword = newline.substr(0, newline.find(" "));
		newwordLength = newword.length();
		if (newwordLength <= 25)
		{
			word_set.insert(newword);
			ss >> temp;
			ss >> temp;
			while (ss >> temp)
			{
				triograms.push_back(temp);
			}

			words[newword.length() - 1].push_back(Word(newword, triograms));

			newword = "";

			triograms.clear();
		}
	}
}

bool Dictionary::contains(const string &word) const
{
	return true;
}


vector<string> Dictionary::get_suggestions(const string& word) const {
vector<string> suggestions;
add_trigram_suggestions(suggestions, word);

return suggestions;
}

