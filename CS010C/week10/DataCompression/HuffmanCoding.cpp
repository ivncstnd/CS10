#include "HuffmanCoding.h"

using namespace std;

HuffmanCoding::HuffmanCoding(ifstream &inFS) {
    HuffmanTree tree;
    while (!inFS.eof()) {
        string input;
        inFS >> input;
        tree.addToken(input);
    }
    tree.inOrder();
}