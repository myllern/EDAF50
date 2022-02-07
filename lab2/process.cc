// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string newline;
  string newword;
  ifstream oldfile("old.txt");
  ofstream newfile;
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
        newword.append(newline + " " + to_string(newline.length() - 3) + " ");
        for (std::size_t i = 0; i <= newline.length() - 3; i++)
        {
          newword += tolower(newline.at(i));
          newword += newline.at(i + 1);
          newword += newline.at(i + 2);
          newword += " ";
        }
      }
      newword += "\n";
      newfile << newword;
      newword = "";
    }
    newfile.close();
    oldfile.close();
  }

  else
    cout << "Unable to open file";

  return 0;
}