#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string numfile, char letter);



int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here

 int charCnt(string numfile, char letter) {
   ifstream inputs; // inputs IS the stream

   // number of times the letter shows up in the input


// opening the file --> streamName.open();
inputs.open(numfile);


string line;

// check if the file is even opening using the .open() function
if (!inputs.is_open())  {
   cout << "Error opening " << numfile << endl;
   exit(1);
}

int counter = 0;

while (getline(inputs, line)) {




   for (int i = 0; i < line.size(); ++i)   {
      if (line.at(i) == letter)   {
         counter = counter + 1;
      }
   }
}
   return counter; 
}
