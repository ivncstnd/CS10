#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "MaxHeap.h"
#include "Key.h"
#include <iostream>

using namespace std;

template <typename K, typename V>
class Node {
    public:
        K key;
        V value;
        Node(K key, V value) : key(key),  value(value) {}
};

template <typename K, typename V>
class HashTable {
    private:
        Node<K, V> **arr;
        int s;
    public:
        HashTable() {
            s = 0;
            arr = new Node<K, V>*[s];
        }
        HashTable(int s) {
            this->s = s;
            arr = new Node<K, V>*[s];
        }
        void put(K key, V value) {
            Node<K, V>* temp = new Node<K, V>(key, value);
            int index = computeHash(key);
            while(arr[index]) {
                index++;
                index %= s;
            }
            arr[index] = temp;
        }
        int size() const {
            return s;
        }
        V get(K key) const {
            int index = computeHash(key);
            while (arr[index]) {
                if (arr[index]->key == key)
                    return arr[index]->value;
                index++;
                index %= s;
            }
        }
        void output(ofstream &outFS) const {
            for (int i = 0; i < s; i++) {
                outFS << arr[i]->key << " " << arr[i]->value << endl;
            }
        }
    private:
        int computeHash(const string &key) const {
            unsigned hash = 5381;
            for (char c : key) {
                hash = (hash * 33) + c;
            }
            return hash % s;
        }
        int computeHash(int key) const {
            return key % s;
        }
};

#endif

