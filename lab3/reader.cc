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

   int start_index = 0;
    int end_index = 0;

    do
    {
        start_index = html.find(" <", start_index);
        end_index = html.find(">", start_index);
        if (start_index != -1)
        {
            html.erase(start_index, (end_index - start_index) + 1);
        }
    } while (start_index != -1);


    for (auto const &w : noWords)
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
