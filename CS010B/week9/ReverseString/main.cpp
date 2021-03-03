#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;
   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
   if(s.size() <= 1) {
      return;
   }
   /**
    * This func recurses through flipString funcs until it hits base case.
    * Once the base case is hit, each case before swaps the first and last
    * characters of the inputted string parameter. Each returns a string with
    * the first and last characters swapped until it reaches the first func call.
    */
   string temp = s.substr(1, s.size() - 2);
   flipString(temp);
   s = s[s.size() - 1] + temp + s[0];
   return;
}


