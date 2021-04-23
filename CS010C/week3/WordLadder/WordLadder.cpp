#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string &dictFile) {
    // Opening dictionary
    ifstream inFS;
    inFS.open(dictFile);
    if (!inFS.is_open()) {
        cout << "cannot open dictionary file" << endl;
        return;
    }

    // Taking input and closing file 
    string input = "";
    while (!inFS.eof()) {
        inFS >> input;
        if (input.size() != 5) {
            cout << "word does not have a size of 5" << endl;
            return;
        }
        dict.push_back(input);
    }
    inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    // Initalizing output file
    ofstream outFS;
    outFS.open(outputFile);
    if (!outFS.is_open()) {
        cout << "cannot open output file" << endl;
        return;
    }

    // Checking for same word input case
    if (start == end) {
        outFS << start;
        outFS.close();
        return;
    }

    // Checking for start and end word existing in dictionary case
    if(!(stringExists(start) && stringExists(end))) {
        cout << "Word passed in does not exist in the dictionary." << endl;
        return;
    }

    // Starting Word Ladder 
    // Initalizing the first step in the ladder
    stack<string> currStep;
    currStep.push(start);

    // Intializing a queue of steps
    queue<stack<string> > ladder;
    ladder.push(currStep);

    // Intializing an iterator for the list
    list<string>::iterator it;

    // While the ladder queue is not empty
    while (!ladder.empty()) {
        // Iterating through the entire dictionary list
        for (it = dict.begin(); it != dict.end(); it++) {
            // If the current iterating word is one letter of from another word on the list
            if (stringsOneOff(ladder.front().top(), *it)) {
                // Copy the current stack and push the new word
                stack<string> nextStep = ladder.front();
                nextStep.push(*it);
                if(*it == end) {
                    // Intializing final ladder to reverse
                    stack<string> finalLadder;
                    // Reversing the ladder
                    while (!nextStep.empty()) {
                        finalLadder.push(nextStep.top());
                        nextStep.pop();
                    }
                    while (!finalLadder.empty()) {
                        outFS << finalLadder.top() << endl;
                        finalLadder.pop();
                    }
                    outFS.close();
                    return;
                }
                // Push the new stack into the queue, and remove the word from the list
                ladder.push(nextStep);
                it = dict.erase(it);
                it--;
            }        
        }
        ladder.pop();
    }
    // If the ladder was not found
    outFS << "No Word Ladder Found." << endl;
    outFS.close();
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

bool WordLadder::stringExists(const string &x) {
    /***
     * Resource taken from https://learn.zybooks.com/zybook/UCRCS010CSpring2021/chapter/26/section/2
     * On the iteration of lists in C++.
     */
    list<string>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++) {
        if (*it == x) {
            return true;
        }
    }
    return false;
}