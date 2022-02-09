#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_set>
#include "word.h"
using std::vector;
using std::unordered_set;
using std::string;

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
unordered_set<string> word_set;
vector<Word> words[25];

};

#endif
