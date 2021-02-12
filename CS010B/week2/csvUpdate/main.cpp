#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   inputFile = argv[1];
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!inFS.is_open()) {
        cout << "Error opening " << inputFile << endl;
        return 1;
   }
   // Read in integers from input file to vector.
   vector<int> v;
   string line;
   string num;

   while(!inFS.eof()) {
       getline(inFS, line);
       stringstream parse(line);
       while(getline(parse, num, ',')){
           v.push_back(stoi(num));
       }
   }
   // Close input stream.
   inFS.close();
   
   // Get integer average of all values read in.
   int avg = 0;

   for(unsigned int i = 0; i < v.size(); i++) {
       avg += v.at(i);
   }

   avg /= v.size();
   
   // Convert each value within vector to be the difference between the original value and the average.
   
   for(unsigned int i = 0; i < v.size(); i++) {
       v.at(i) -= avg;
   }
   
   // Create output stream and open/create output csv file.

    ofstream outFS;
    outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!outFS) {
        cout << "Error opening " << outputFile << endl;
        exit(1);
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(int unsigned i = 0; i < v.size(); i++) {
       outFS << v.at(i);
       if(i != v.size()-1) {
           outFS<<",";
       }
   }
   // Close output stream.
   outFS.close();

   return 0;
}