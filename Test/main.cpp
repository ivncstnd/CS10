#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

void scramble(int, int, vector<char>);

int main() {
    srand(time(0));
    vector<char> scrambleChars;
    char input;
    int size;
    int names;
    cout << endl << "Enter characters. '0' to stop." << endl;
    cin >> input;
    while(input != '0') {
        scrambleChars.push_back(input);
        cin >> input;
    }
    cout << endl << "Current inputted characters: " << endl;
    for(int i = 0; i < scrambleChars.size(); i++) {
        cout << scrambleChars.at(i);
    }
    cout << endl;
    cout << endl << "Enter amount of names." << endl;
    cin >> names; 
    cout << endl << "Enter name sizes." << endl;
    cin >> size;
    cout << endl;
    scramble(names, size, scrambleChars);
    return 0;
}

void scramble(int repeat, int wordSize, vector<char> db) {
    string name = "";
    for(int i = 0; i < repeat; ++i) {
        vector<char> copy = db;
        for (int j = 0; j < wordSize; ++j) {
            int index = rand() % copy.size();
            name += copy.at(index);
            copy.erase(copy.begin() + index);
        }
        if(i % 9 == 0 && i != 0) {
            cout << name << endl;
        }
        cout << name << "  ";        
        name = "";
    }
    cout << endl << "Complete." << endl;
}
