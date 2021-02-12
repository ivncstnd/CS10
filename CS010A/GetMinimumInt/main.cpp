#include <iostream>
#include <vector>
using namespace std;

int GetMinimumInt(vector<int> listInts) {
   unsigned int i = 0;
   int smallestInt = listInts.at(0);

   for(i = 1; i < listInts.size(); ++i) {
      if(smallestInt > listInts.at(i)) {
         smallestInt = listInts.at(i);
      }
   }

   return smallestInt;
}

int main() {

   unsigned int i = 0;
   unsigned int vSize = 0;

   cout << "Vector size: ";
   cin >> vSize;

   vector<int> elements(vSize);

   cout << "Input values: \n";
   for(i = 0; i < vSize; ++i) {
      cin >> elements.at(i);
   }
   cout << endl;

   int min = GetMinimumInt(elements);
   cout << "Minimum: " << min << endl;

   cout << "Minimum removed from values: \n";
   for(i = 0; i < vSize; ++i) {
      elements.at(i) -= min;
      cout << elements.at(i) << " ";
   }
   cout << endl;

   return 0;
}
