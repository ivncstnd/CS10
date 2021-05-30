#ifndef __HUFFMANCODING_H__
#define __HUFFMANCODING_H__

#include "HashTable.h"
#include "MaxHeap.h"
#include "Key.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class HuffmanCoding {
    private:
        /* Stores frequency of string apperances to construct HashTables */
        MaxHeap frequencyQueue;

        /* Stores string tokens/codes of a text file in appearance order */
        vector<string> fileBuffer;

        /* Tables of token-to-code and code-to-token */
        HashTable<string, int>* encodeTable;
        HashTable<int, string>* decodeTable;

    public:
        /* Default constructor initializes all buffers, tables, and queue to 0 */
        HuffmanCoding() : frequencyQueue(0), fileBuffer(0), encodeTable(0), decodeTable(0) {}

        /* Store a new file's decoded buffer and encode / decode table */
        void storeNewFile(ifstream &);

        /* Given encode & decode tables, store integer encoded file */
        void storeEncodedFile(ifstream &);

        /* Given encode & decode tables, store string decoded file */
        void storeDecodedFile(ifstream &);

        /* Given a file, read encode & decode tables */
        void readHashTables(ifstream &);

        /* Write encode & decode tables to a single file */
        void writeHashTables(ofstream &);

        /* Encode a string decoded buffer */
        void encodeBuffer(ofstream &);

        /* Decode a integer encoded buffer */
        void decodeBuffer(ofstream&);

    private:
        /* Stores strings tokens into fileBuffer */
        void storeDecodedBuffer(ifstream &);

        /* Stores string codes into fileBuffer */
        void storeEncodedBuffer(ifstream &);

        /* Creates frequency queue from a decoded buffer by iterating through */
        void storeFrequency();

        /* Creates encode & decode tables from emptying a frequency queue */
        void storeTables();

        /* Tokenizes strings from punctuation */
        void tokenize(string s);
};

#endif