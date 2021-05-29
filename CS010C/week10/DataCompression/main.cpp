#include "MaxHeap.h"
#include "Key.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "HashTable.h"

using namespace std;


void tokenize(string s);
MaxHeap test;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cerr << "Usage error: expected <executable> <input> <output>" << endl;
        exit(1);
    }

    ifstream inFS(argv[1]);
    if (!inFS) {
        cerr << "Input file not found." << endl;
        exit(1);
    }

    ofstream outFS(argv[2]); 
    if (!outFS) {
        cerr << "Output file not found." << endl;
        exit(1);
    }

    string input;
    while (!inFS.eof()) {
        inFS >> input;
        tokenize(input);
    }
    inFS.close();
    

    HashTable<string, int>* encodeTable = new HashTable<string, int>(test.size());
    HashTable<int, string>* decodeTable = new HashTable<int, string>(test.size());
    int i = 0;
    while (!test.empty()) {
        Key* out = test.dequeue();
        out->code += i;
        cout << "token: " << out->token  << "        code: " << out->code  << "     frequency: " << out->frequency << endl;
        outFS << "token: " << out->token  << "        code: " << out->code  << "        frequency: " << out->frequency << endl;
        encodeTable->put(out->token, out->code, out->frequency);
        decodeTable->put(out->code, out->token, out->frequency);
        i++;
    }



    return 0;
}

void tokenize(string s) {
    string temp;
    for(auto c : s) {
        if(!ispunct(c)) {
            temp += c;
        } else if (!temp.empty()) {
            test.enqueue(temp);
            temp = c;
            test.enqueue(temp);
            temp = "";
        } else {
            temp = c;
            test.enqueue(temp);
            temp = "";
        }
    }
    test.enqueue(temp);
}