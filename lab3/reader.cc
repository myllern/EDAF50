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
    ifstream file;
    file.open(s);
    string row;

    while (getline(file, row))
    {
        html += row + "\n";
    }
    html.erase(remove(html.begin(), html.end(), '<'), html.end());
    html.erase(remove(html.begin(), html.end(), '>'), html.end());
    cout << html;
}

void TagRemover::print(ostream &os)
{
    os << html;
}

int main()
{
    TagRemover tr("test.html");
}
