#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "MaxHeap.h"
#include "Key.h"
#include <iostream>

using namespace std;

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node(K key, V value) : key(key),  value(value) {}
};

template <typename K, typename V>
class HashTable {
    private:
        Node<K, V> **arr;
        int size = 0;
    public:
        HashTable(int);
        void put(K, V, int);
        V get(K) const;
    private:
        int computeHash(int);
};

#endif

template <typename K, typename V>
HashTable<K, V>::HashTable(int s) {
    size = s;
    arr = new Node<K, V>*[size];
}

template <typename K, typename V>
int HashTable<K, V>::computeHash(int key) {
    return key % size;
}

template <typename K, typename V>
void HashTable<K, V>::put(K key, V value, int reference) {
    Node<K, V>* temp = new Node<K, V>(key, value);
    int index = computeHash(reference);
    while(arr[index]) {
        index++;
        index %= size;
    }
    arr[index] = temp;
}

template <typename K, typename V>
V HashTable<K, V>::get(K key) const {
    int index = computeHash(key);
    while (arr[index]) {
        int counter = 0;
        if (counter++ > size) 
            return nullptr;
        if (arr[index]->key == key)
            return arr[index]->value;
        index++;
        index %= size;
    }
}