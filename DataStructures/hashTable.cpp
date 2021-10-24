//----------------------------------------------------------------------------------
// [ HashTable ]
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
    static const int HASH_MAX = 7;
    static const int HASH_CHAIN_MAX = 50;
    static const int HASH_VAL = 17;

    int data[HASH_MAX][HASH_CHAIN_MAX] = {};
    string keys[HASH_MAX][HASH_CHAIN_MAX] = {};
    int length[HASH_MAX] = {};

public:
    static int getHash(const string& s) {
        int key = 0;

        for (int i = 0; i < s.size(); ++i) {
            key = (key * HASH_VAL) + s[i];
        }

        if (key < 0) key *= -1;

        return key % HASH_MAX;
    }

public:
    void insert(const string& s_key, int val) {
        int key = getHash(s_key);

        for (int i = 0; i < length[key]; ++i) {
            if (s_key == keys[key][i]) return;
        }

        keys[key][length[key]] = s_key;
        data[key][length[key]] = val;
        length[key]++;
    }

    int& find(const string& s_key) {
        int key = getHash(s_key);

        for (int i = 0; i < length[key]; ++i) {
            if (s_key == keys[key][i]) return data[key][i];
        }

        keys[key][length[key]] = s_key;
        data[key][length[key]] = 0;
        length[key]++;

        return data[key][length[key] - 1];
    }
};


int main() {
    HashTable hashTable;

    hashTable.insert("피카츄", 25);
    hashTable.insert("라이츄", 26);
    hashTable.insert("파이리", 4);
    hashTable.insert("꼬부기", 7);
    hashTable.insert("버터플", 12);
    hashTable.insert("야도란", 80);

    cout << HashTable::getHash("파이리") << ":\t" << hashTable.find("파이리") << endl;
    cout << HashTable::getHash("버터플") << ":\t" << hashTable.find("버터플") << endl;
    cout << HashTable::getHash("피카츄") << ":\t" << hashTable.find("피카츄") << endl;
    cout << HashTable::getHash("피존투") << ":\t" << hashTable.find("피존투") << endl;
    hashTable.find("야도란") = 63;
    cout << HashTable::getHash("야도란") << ":\t" << hashTable.find("야도란") << endl;
}