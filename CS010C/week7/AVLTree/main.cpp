#include <iostream>
#include "AVLTree.h"

using namespace std;

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Print" << endl
    << "3. Visualize" << endl
    << "4. Quit" << endl;
  cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  AVLTree tree;

  int choice = menu();

  string entry;

  while (choice != 4) {

    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline(cin, entry);
      cout << endl;

      tree.insert(entry);

    } else if (choice == 2) {
      tree.printBalanceFactors();

    } else if (choice == 3) {
        tree.visualizeTree("o.dot");
    }
    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }

  return 0;
}