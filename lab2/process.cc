// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string newline;
  string newword;
  ifstream oldfile ("old.txt");
  ofstream newfile;
  newfile.open ("new.txt");

  if (oldfile.is_open() || newfile.is_open())
  {
    while ( getline (oldfile,newline) )
    {
        if (len(newline) <= 3)
        {
            newword.append(newline + "\n"); 
        }else{
            
        }
        
        



        newfile << newword;
        newword = "";
    
    }
    newfile.close();
    oldfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}