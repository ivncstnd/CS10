#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string filename);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}
 
int fileSum(string filename) {

    ifstream inFS;
    int sum = 0;

    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    else {
        int i;
        while(inFS >> i) {
            sum += i;
        }
    }

    return sum;
}
