#include "HuffmanCoding.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cerr << "Usage error: expected ./a.out [flags] [input]" << endl;
        cerr << "optional:             ./a.out [flags] [input] [table]" << endl;
        exit(1);
    }
    
    ifstream inputFile(argv[2]);
    if (!inputFile) {
        cerr << "Input file not found." << endl;
        exit(1);
    }

    HuffmanCoding file;
    string arg = argv[1];
    if (arg == "-c" || arg == "--compress") {
        // if no table was passed -- new file compress
        if (argc < 4) {
            file.storeNewFile(inputFile);
            ofstream outputFile(argv[2]);
            if (!outputFile) {
                cerr << "Error opening output file" << endl;
                exit(1);
            }
            file.encodeBuffer(outputFile);
            ofstream outputTables("tables.txt");
            file.writeHashTables(outputTables);
        } else {
            ifstream inputTables(argv[3]);
            if (!inputTables) {
                cerr << "Input tables not found." << endl;
                exit(1);
            }
            file.readHashTables(inputTables);
            file.storeDecodedFile(inputFile);
            ofstream outputFile(argv[2]);
            if (!outputFile) {
                cerr << "Error opening output file" << endl;
                exit(1);
            }
            file.encodeBuffer(outputFile);
        }
    }  else if (arg == "-d" || arg == "--decompress") {
        if (argc < 4) {
            cerr << "Usage error: required <table>" << endl;
        } else {
            ifstream inputTables(argv[3]);
            if (!inputTables) {
                cerr << "Input tables not found." << endl;
                exit(1);
            }
            file.readHashTables(inputTables);
            file.storeEncodedFile(inputFile);
            ofstream outputFile(argv[2]);
            if (!outputFile) {
                cerr << "Error opening output file" << endl;
                exit(1);
            }
            file.decodeBuffer(outputFile);
        }
    } else {
        cerr << "Usage error: invalid <flag>" << endl << endl;
        cerr << "-c, --compress                 compress a file given input, optional hash table" << endl;
        cerr << "-d, --decompress               decompress a file given input, hash table" << endl;
        exit(1);
    }

    return 0;
}
