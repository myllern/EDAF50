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
    map<string, string> noWords = {{"&lt", "<"},
                                   {"&gt", ">"},
                                   {"&nbsp", " "},
                                   {"&amp", "&"}};

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
    int b = 0;
    for (const auto &pair : noWords)
    {
        
        int char_index = -1;
        do
        {
            char_index = html.find(pair.first, char_index + 1);
            if (char_index != -1)
            {
                html.replace(char_index, pair.first.size(), pair.second);
            }
        } while (char_index != -1);


    };
    cout << html;

    

    // void TagRemover::print(ostream & os)
    // {
    //     os << html;
    // }
}

int main()
{
    TagRemover tr("test.html");
}
