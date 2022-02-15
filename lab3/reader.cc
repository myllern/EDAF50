#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "reader.h"
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

TagRemover::TagRemover(std::string s)
{
    file = s;

    ifstream text_file;

    text_file.open(s);

    string text_row;

    string html;

    vector<int> start_tags;
    vector<int> end_tags;

    while (getline(text_file, text_row))
    {
        if (text_file.good())
        {
            html += text_row + "\n";
        }
    }

    int current_tag = -1;

    do
    {
        current_tag = html.find(" <", current_tag + 1);
        if (current_tag != -1)
        {
            start_tags.push_back(current_tag);
        }
    } while (current_tag != -1)

    //    std::cout << html;
}

int main()
{

    TagRemover tr("test.html");
}
