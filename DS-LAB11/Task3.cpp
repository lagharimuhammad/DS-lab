#include <iostream>
using namespace std;

class HashNode {
public:
    int key;
    int value;
    HashNode* next;
    
    HashNode(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class Hash {
private:
    HashNode** table;
    int capacity;
    
    int hashFunction(int key) {
        return key % capacity;
    }
    
public:
    Hash(int size) {
        capacity = size;
        table = new HashNode*[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }
    
    void insert(int key, int value) {
        int index = hashFunction(key);
        
        if (table[index] == nullptr) {
            table[index] = new HashNode(key, value);
            return;
        }
        
        HashNode* current = table[index];
        while (current->next != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        
        if (current->key == key) {
            current->value = value;
        } else {
            current->next = new HashNode(key, value);
        }
    }
    
    int search(int key) {
        int index = hashFunction(key);
        HashNode* current = table[index];
        
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        
        if (table[index] == nullptr) {
            return;
        }
        
        if (table[index]->key == key) {
            HashNode* temp = table[index];
            table[index] = table[index]->next;
            delete temp;
            return;
        }
        
        HashNode* current = table[index];
        HashNode* prev = nullptr;
        
        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }
        
        if (current == nullptr) {
            return;
        }
        
        prev->next = current->next;
        delete current;
    }
    
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            HashNode* current = table[i];
            
            while (current != nullptr) {
                cout << "[" << current->key << ":" << current->value << "]";
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << endl;
        }
    }
    
    ~Hash() {
        for (int i = 0; i < capacity; i++) {
            HashNode* current = table[i];
            while (current != nullptr) {
                HashNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main() {
    Hash hashTable(7);
    
    hashTable.insert(10, 100);
    hashTable.insert(20, 200);
    hashTable.insert(15, 150);
    hashTable.insert(7, 70);
    hashTable.insert(21, 210);
    hashTable.insert(14, 140);
    
    cout << "Hash Table after insertions:" << endl;
    hashTable.display();
    cout << endl;
    
    cout << "Search for key 15: " << hashTable.search(15) << endl;
    cout << "Search for key 25: " << hashTable.search(25) << endl;
    cout << endl;
    
    hashTable.remove(15);
    cout << "Hash Table after removing key 15:" << endl;
    hashTable.display();
    cout << endl;
    
    hashTable.insert(20, 201);
    cout << "Hash Table after updating key 20:" << endl;
    hashTable.display();
    cout << endl;
    
    hashTable.insert(28, 280);
    cout << "Hash Table after inserting key 28 (collision with 21):" << endl;
    hashTable.display();
    
    return 0;
}