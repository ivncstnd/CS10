#include "HuffmanCoding.h"

using namespace std;

void HuffmanCoding::storeNewFile(ifstream &inFS) {
    storeDecodedBuffer(inFS);
    storeFrequency();
    storeTables();
}

void HuffmanCoding::storeEncodedFile(ifstream &inFS) {
    storeEncodedBuffer(inFS);
}

void HuffmanCoding::storeDecodedFile(ifstream &inFS) {
    storeDecodedBuffer(inFS);
}

void HuffmanCoding::readHashTables(ifstream &inFS) {
    int tableSize = 0;
    inFS >> tableSize;
    encodeTable = new HashTable<string, int>(tableSize);
    decodeTable = new HashTable<int, string>(tableSize);
    for (int i = 0; i < tableSize; i++) {
        string token = "";
        int code = 0;
        inFS >> token;
        inFS >> code;
        encodeTable->put(token, code);
    }
    for (int i = 0; i < tableSize; i++) {
        int token = 0;
        string code = "";
        inFS >> token;
        inFS >> code;
        decodeTable->put(token, code);
    }
}

void HuffmanCoding::writeHashTables(ofstream &outFS) {
    outFS << encodeTable->size() << endl;
    encodeTable->output(outFS);
    decodeTable->output(outFS);
}

void HuffmanCoding::encodeBuffer(ofstream &outFS) {
    for (int i = 0; i < fileBuffer.size(); i++) {
        if (fileBuffer.at(i) == "\n" || fileBuffer.at(i) == "") {
            outFS << fileBuffer.at(i);
            continue;
        }
        outFS << encodeTable->get(fileBuffer.at(i)) << " ";
    }
}

void HuffmanCoding::decodeBuffer(ofstream &outFS) {
     for (int i = 0; i < fileBuffer.size(); i++) {
        if (fileBuffer.at(i) == "\n" || fileBuffer.at(i) == "") {
            outFS << fileBuffer.at(i);
            continue;
        }
        int temp = stoi(fileBuffer.at(i));
        outFS << decodeTable->get(temp) << " ";
    }
}


void HuffmanCoding::storeDecodedBuffer(ifstream &inFS) {
    while (!inFS.eof()) {
        string line;
        while (getline(inFS, line)) {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                tokenize(word);
            }
            fileBuffer.push_back("\n");
        }
    }
}

void HuffmanCoding::storeEncodedBuffer(ifstream &inFS) {
    while (!inFS.eof()) {
        string line;
        while (getline(inFS, line)) {
            stringstream ss(line);
            string code;
            while (ss >> code) {
                fileBuffer.push_back(code);
            }
            fileBuffer.push_back("\n");
        }
    }
}

void HuffmanCoding::storeFrequency() {
    if (!fileBuffer.empty()) {
        for (int i = 0; i < fileBuffer.size(); i++) {
            if (fileBuffer.at(i) == "\n" || fileBuffer.at(i) == "")
                continue;
            frequencyQueue.enqueue(fileBuffer.at(i));
        }
    }
}

void HuffmanCoding::storeTables() {
    if (!frequencyQueue.empty()) {
        encodeTable = new HashTable<string, int>(frequencyQueue.size());
        decodeTable = new HashTable<int, string>(frequencyQueue.size());
        int i = 0;
        while (!frequencyQueue.empty()) {
            Key* out = frequencyQueue.dequeue();
            out->code += i;
            cout << "token: " << out->token  << "        frequency: " << out->frequency  << "     code: " << out->code << endl;
            encodeTable->put(out->token, out->code);
            decodeTable->put(out->code, out->token);
            i++;
        }
    }
}

void HuffmanCoding::tokenize(string s) {
    string temp;
    for(auto c : s) {
        if(!ispunct(c)) {
            temp += c;
        } else if (!temp.empty()) {
            fileBuffer.push_back(temp);
            temp = c;
            fileBuffer.push_back(temp);
            temp = "";
        } else {
            temp = c;
            fileBuffer.push_back(temp);
            temp = "";
        }
    }
    fileBuffer.push_back(temp);
}