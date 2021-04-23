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
    while (!inFS.eof()) {
        inFS >> curr;
        if (curr.size() != 5) {
            cout << "word does not have a size of 5" << endl;
            return;
        }
        dict.push_back(curr);
    }
    inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    if (start == end) {
        exit(0);
    }
    stack<string> currStep;
    currStep.push(start);
    queue<stack<string> > ladder;
    ladder.push(currStep);
    while (!ladder.empty()) {
        /***
         * Resource taken from https://en.cppreference.com/w/cpp/container/list
         * On the iteration of lists in C++.
         */
        for (auto it = dict.begin(); it != dict.end(); it++) {
            if (stringsOneOff(ladder.front().top(), *it)) {
                stack<string> nextStep = ladder.front();
                nextStep.push(*it);
                if(*it == end) {
                    stack<string> finalLadder;
                    // Reverse the ladder
                    while (!nextStep.empty()) {
                        finalLadder.push(nextStep.top());
                        nextStep.pop();
                    }
                    ofstream outFS;
                    outFS.open(outputFile);
                    if (!finalLadder.empty()) {
                        if (!outFS.is_open()) {
                            cout << "Error opening " << outputFile << endl;
                            exit(1);
                        }
                        while (!finalLadder.empty()) {
                            outFS << finalLadder.top() << endl;
                            finalLadder.pop();
                        }
                        outFS.close();
                    }
                    exit(0);
                }
                ladder.push(nextStep);
                it = dict.erase(it);
                it--;
            }
        }
        ladder.pop();
    }
    if (ladder.empty()) {
        cout << "No Word Ladder found." << endl;
        exit(0);
    }
    return;
} 

bool WordLadder::stringsOneOff(const string &x, const string &y) const {
    int offsetCount = 0;
    for (int i = 0; i < 5; i++) {
        if (x.at(i) != y.at(i)) {
            offsetCount++;
        }
    }
    return offsetCount == 1;
}
