// reading a text file
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
  ifstream oldfile("engmix.txt");
  ofstream newfile;
  list<string> lista;
  newfile.open("new.txt");

  if (oldfile.is_open() || newfile.is_open())
  {
    while (getline(oldfile, newline))
    {
      if (newline.length() <= 3)
      {
        newword.append(newline + " " + to_string(0) + "\n");
      }
      else
      {
        newword.append(newline + " " + to_string(newline.length() - 2) + " ");
        for (std::size_t i = 0; i <= newword.length() - 3; i++)
        {
          lista.push_back(newword);
        }

      }
    }
    newfile.close();
    oldfile.close();
  }

  else
    cout << "Unable to open file";

  newline.clear();
  newword.clear();
  return 0;
}
