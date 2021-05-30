#include "HuffmanCoding.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    
    if (argc < 2) {
        cerr << "Usage error: expected <executable> <input>" << endl;
        exit(1);
    }
    

    ifstream inFS(argv[1]);
    if (!inFS) {
        cerr << "Input file not found." << endl;
        exit(1);
    }

    
    ifstream inTableFS(argv[2]);
    if (!inTableFS) {
        cerr << "Input file not found." << endl;
        exit(1);
    }
    
    

    ofstream outFS("output"); 
    if (!outFS) {
        cerr << "Output file not found." << endl;
        exit(1);
    }

    /*
    ofstream outTableFS("tables");
     if (!outTableFS) {
        cerr << "Output file not found." << endl;
        exit(1);
    }
    */

    HuffmanCoding test;
    /*
    test.storeNewFile(inFS);
    test.encodeBuffer(outFS);
    test.writeHashTables(outTableFS);
    */
    
    test.readHashTables(inTableFS);
    test.storeEncodedFile(inFS);
    test.decodeBuffer(outFS);

    return 0;
}
