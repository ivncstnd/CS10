#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int charCnt(string filename, char ch);


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

int charCnt(string filename, char ch) {

   ifstream inFS;
   char c;
   int count = 0;

   inFS.open(filename);

   if(!inFS.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(1);
   }
   else {
      while(!inFS.eof()){
         inFS.get(c);
         if(c == ch) {
            count++;
         }

      }
   }

   return count;
}
