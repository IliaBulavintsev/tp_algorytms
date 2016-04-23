#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int DefaultTableSize = 8;
const int GrowFactor = 2;
const int MaxOccupation = 3;

int Hash(const string& data, int tableSize){

    int hash = 0;
    for (int i = 0; i < data.size() ; ++i) {
        hash = (hash * 127 + data[i]) % tableSize;
    }
    return hash;
}

template <class T>
struct HashTableNode{
    T Data;
    HashTableNode<T> *Next;
    HashTableNode() : Next(0) {}
    HashTableNode(const T& data, HashTableNode *next): Data(data),  Next(next) {};
};

template <class T>
class HashTable{
public:
    HashTable();
    ~HashTable();
    bool Has(const T& data) const;
    bool Add(const T& data);
    bool Delete(const T& data);
private:
    vector<HashTableNode<T>*> table;
    unsigned  int keyCount;
    void growTable();
};

template <class T>
HashTable<T>::HashTable(): keyCount(0)
{
    table.resize(DefaultTableSize);
}

template <class T>
bool HashTable::Has(const T &data) const{
    int hash = Hash(data, table.size());
    HashTableNode<T>* node = table[hash];
    while (node !=0 && node->Data != data){
        node = node->Next;
    }
    return node != 0;
}

template <class T>
bool HashTable<T>::Delete(const T &data) {
    int hash = Hash(data, table.size());
    HashTableNode<T> *node = table[hash];
    if (node->Data == data) {
        table[hash] = node->Next;
        delete node;
        return true;
    }
    while ( node->Next != 0 && node->Next->Data != data){
        node = node->Next;
    }
    if (node->Next == 0) {
        return false;
    }
    HashTableNode<T>* nodeNext = node->Next;
    node->Next = node->Next->Next;
    delete nodeNext;
    return true;

}

template <class T>
 bool HashTable::Add(const T &data) {
    if ( Has(data) ){ // не оптимально
        return false;
    }
    if (keyCount + 1 > table.size() * MaxOccupation) {
        growTable();
    }

    int hash = Hash(data, table.size());
    table[hash] = new HashTableNode<T>(data, table[hash]);
    keyCount++;
    return true;
}

template <class T>
void HashTable::growTable(){
    vector<HashTableNode<T>*> newTable(table.size() * GrowFactor, 0);
    for (unsigned int i = 0; i < table.size(); ++i) {
        HashTableNode<T>* node = table[i];
        while (node != 0){
            HashTableNode<T> * nextNode = node->Next;
            int newHash = Hash(node->Data, newTable.size());
            node->Next = newTable[newHash];
            newTable[newHash] = node;
            node = nextNode;
        }

    }
    table = newTable;
}
int main() {
    char op;
    string word;
    cin >> op >> word;
    return 0;
}