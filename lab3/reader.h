#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;


class TagRemover {
public:
	TagRemover(std::string file);
	// void print(ostream& os);
    
private:
	string file, html;
	//void traverseString(std::string &s, int i);
};





#endif
