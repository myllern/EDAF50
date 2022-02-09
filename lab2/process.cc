// reading a text infile
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string newline;
  string newword;
  string triads;
  ifstream infile("old.txt");
  ofstream outFile;
  list<string> list;

  outFile.open("new.txt");

  if (infile.is_open() || outFile.is_open())
  {
    while (getline(infile, newline))
    {

      if (newline.length() <= 3)
      {
        newword.append(newline + " " + to_string(0) + "\n");
      }
      else
      {
        newword.append(newline + " " + to_string(newline.length()) + " ");
        newline[0] = tolower(newline[0]);
        for (std::size_t i = 0; i < newline.length() - 2; i++)
        {
          list.push_back(newline.substr(i, 3).append(" "));
        }
        list.sort();
        for (string i : list)
        {
          newword.append(i);
        }

        list.clear();
        newword.append("\n");
        outFile << newword;
        newword = "";
      }
    }
    outFile.close();
    infile.close();
  }

  else
    cout << "Unable to open infile";

  newline.clear();
  newword.clear();
  return 0;
}
