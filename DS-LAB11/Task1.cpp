#include <iostream>
using namespace std;

struct Node {
    string key;
    Node* next;
    Node(string k) {
        key = k;
        next = 0;
    }
};

class Hash {
public:
    int size;
    Node** table;

    Hash(int s) {
        size = s;
        table = new Node*[size];
        for(int i = 0; i < size; i++) table[i] = 0;
    }

    int hashFunc(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++) sum += s[i];
        return sum % size;
    }

    void insertKey(string s) {
        int idx = hashFunc(s);
        Node* n = new Node(s);
        if(table[idx] == 0) {
            table[idx] = n;
        } else {
            Node* t = table[idx];
            while(t->next) t = t->next;
            t->next = n;
        }
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* t = table[i];
            while(t) {
                cout << t->key << " ";
                t = t->next;
            }
            cout << "
";
        }
    }
};

int main() {
    Hash h(5);
    h.insertKey("Aaaaaa");
    h.insertKey("Bbbbbb");
    h.insertKey("Cccccc");
    h.insertKey("Azzzzz");
    h.display();
}
