#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>
#include "reader.h"
using namespace std;

TagRemover::TagRemover(std::string s)
{
    map<string, string> specialChars = {{"&lt", "<"},
                                   {"&gnoWords
noWords{"&amp", "&"}};

    ifstream file;
    file.open(s);
    string row;
    string temp_value;

    while (getline(file, row))
    {
        html += row + "\n";
    }

    html.erase(remove(html.begin(), html.end(), '<'), html.end());
    html.erase(remove(html.begin(), html.end(), '>'), html.end());

    for (auto const &w : specialChars)
    {
        std::regex rm(w.first);
        html = regex_replace(html, rm, w.second);
    }

    cout << html;
}

int main()
{
    TagRemover tr("test.html");
}
