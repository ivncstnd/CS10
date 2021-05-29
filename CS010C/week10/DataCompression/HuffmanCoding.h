#ifndef __HUFFMANCODING_H__
#define __HUFFMANCODING_H__

#include "HashTable.h"
#include "MaxHeap.h"
#include "Key.h"

using namespace std;

class HuffmanCoding {
    private:
        HashTable<string, int> encoder;
        HashTable<int, string> decoder;
    public:
        HuffmanCoding(HashTable<string, int>, HashTable<int, string>);
};

#endif