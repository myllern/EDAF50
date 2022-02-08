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
  list<string> list;
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

string gen_triads(string word)
{
  string[] tri_arr;
  for (std::size_t i = 0; i <= word.length() - 3; i++)
  {
    


  }
}