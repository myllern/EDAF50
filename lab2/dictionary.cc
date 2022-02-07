#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::unordered_set;
using std::vector;
using namespace std;

Dictionary::Dictionary()

{
	words_set = unordered_set<string>();
	ifstream infile("words.txt");

}
	

bool Dictionary::contains(const string &word) const
{
	return true;
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	vector<string> suggestions;
	return suggestions;
}
