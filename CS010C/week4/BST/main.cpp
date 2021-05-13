#include <iostream>
#include <limits>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}


int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main() {
    BSTree tree;

    int choice = menu();

    string entry;
  
    while (choice != 8) {
    
        if (choice == 1) {
          cout << "Enter string to insert: ";
          getline(cin, entry);
          tree.insert(entry);
          cout << endl;
        } else if (choice == 2) {
          cout << "Enter string to remove: ";
          getline(cin, entry);
          tree.remove(entry);
          cout << endl;
        } else if (choice == 3) {
          printOrders(&tree);
        } else if (choice == 4) {
          cout << "Enter string to search for: ";
          getline(cin, entry);
          if (tree.search(entry) == 1) {
            cout << entry << " is within the tree.";
          } else {
            cout << entry << " is not within the tree.";
          }
          cout << endl;
        } else if (choice == 5) {
          cout << "Smallest: " << tree.smallest() << endl;
        } else if (choice == 6) {
          cout << "Largest: " << tree.largest() << endl;
        } else if (choice == 7) {
          cout << "Enter string: ";
          getline(cin, entry);
          if (tree.height(entry) != -1) {
            cout << entry << "'s height on the tree is " << tree.height(entry) << "." << endl;
          } else {
            cout << entry << " does not exist on the tree." << endl;
          }
          
        }
        //fix buffer just in case non-numeric choice entered
        choice = menu();
    }
    return 0;
  
}