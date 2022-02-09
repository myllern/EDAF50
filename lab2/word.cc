#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "word.h"

using std::string;
using std::vector;
using namespace std;


Word::Word(const string &w, const vector<string> &t) : word(w), trigrams(t) {}

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	unsigned int count = 0;
	int nrOfTrigrams = word.length() - 2;

	for (std::size_t i = 0; i < nrOfTrigrams; i++)
	{
		if(std::find(std::begin(t), std::end(t), trigrams[i]) != std::end(t)){
			count++;
			std::cout << "Hee";
		}


	}

	return count;
}
