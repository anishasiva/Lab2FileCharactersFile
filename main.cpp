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


// check if the file is even opening using the .open() function
if (!inputs.is_open())  {
   cout << "Error opening " << numfile << endl;
   exit(1);
}

string line;

// counter counts the amount of times the given character is in the input
// make sure to initialize this OUTSIDE of the while loop
int counter = 0;

/* GETLINE FORMAT --> getline(streamName,line) you dont need to initialize 
the line cuz getline already takes in the line that the input or in this
case the file has
*/
while (getline(inputs, line)) {
   for (long unsigned int i = 0; i < line.size(); ++i)   {

      // letter is already in the parameters of the function so dont need to initialize
      // line below checks if the letters in the line are equal to the given char letter
      if (line.at(i) == letter)   {
         counter = counter + 1;
      }
   }
}
// return the counter OUTSIDE of the while loop
   return counter; 
}
