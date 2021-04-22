#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string &dictFile) {
    ifstream inFS;
    inFS.open(dictFile);
    if (!inFS.is_open()) {
        cout << "cannot open dictionary file" << endl;
        return;
    }
    string curr = "";
    while (!(inFS.eof())) {
        inFS >> curr;
        if (curr.size() != 5) {
            cout << "word does not have a size of 5" << endl;
            return;
        }
        dict.push_back(curr);
    }
    inFS.close();
    return;
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {

}