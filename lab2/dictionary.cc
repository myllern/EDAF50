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
		newword[0] = tolower(newword[0]);
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

			cout << words->pop_back().getWord();

			newword = "";

			triograms.clear();
		}
	}
}

bool Dictionary::contains(const string &word) const
{
	for (string s : word_set)
	{
		if (s == word)
		{
			return true;
		}
	}

	return false;
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(std::vector<std::string> &suggestions, const string &word) const
{
	vector<string> wordTrigrams;
	vector<Word> wordsVector = words[word.length() - 1];
	vector<Word> test = words[3];

	// for (Word w : test)
	// {
	// 	cout << "2sdad";
	// 	cout << w.get_word();
	// }

	int wordLength = word.length();

	for (size_t i = 0; i < word.length() - 3; i++)
	{
		wordTrigrams.push_back(word.substr(i, 3));
	}
	wordsVector.insert(wordsVector.end(), words[wordLength - 2].begin(), words[wordLength - 2].end());
	wordsVector.insert(wordsVector.end(), words[wordLength].begin(), words[wordLength].end());

	for (Word listWordTri : wordsVector)
	{
		if (listWordTri.get_matches(wordTrigrams) >= wordLength - 2)
		{
			suggestions.push_back(listWordTri.get_word());
		}
	}
}