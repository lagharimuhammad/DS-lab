#include <iostream>
using namespace std;

struct DictionaryNode {
    string word;
    string meaning;
    DictionaryNode* next;
    
    DictionaryNode(string w, string m) {
        word = w;
        meaning = m;
        next = nullptr;
    }
};

class Dictionary {
private:
    DictionaryNode** table;
    int capacity;
    
    int calculateHash(const string& word) {
        int sum = 0;
        for (char c : word) {
            sum += (int)c;
        }
        return sum % capacity;
    }
    
public:
    Dictionary(int size = 100) {
        capacity = size;
        table = new DictionaryNode*[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }
    
    void AddRecord(string word, string meaning) {
        int index = calculateHash(word);
        
        if (table[index] == nullptr) {
            table[index] = new DictionaryNode(word, meaning);
            return;
        }
        
        DictionaryNode* current = table[index];
        while (current->next != nullptr) {
            if (current->word == word) {
                current->meaning = meaning;
                return;
            }
            current = current->next;
        }
        
        if (current->word == word) {
            current->meaning = meaning;
        } else {
            current->next = new DictionaryNode(word, meaning);
        }
    }
    
    string WordSearch(string word) {
        int index = calculateHash(word);
        DictionaryNode* current = table[index];
        
        while (current != nullptr) {
            if (current->word == word) {
                return current->meaning;
            }
            current = current->next;
        }
        
        return "ERROR: Word not found!";
    }
    
    void DeleteWord(string word) {
        int index = calculateHash(word);
        
        if (table[index] == nullptr) {
            cout << "ERROR: Word not found!" << endl;
            return;
        }
        
        if (table[index]->word == word) {
            DictionaryNode* temp = table[index];
            table[index] = table[index]->next;
            delete temp;
            cout << "key " << word << " deleted successfully!" << endl;
            return;
        }
        
        DictionaryNode* current = table[index];
        DictionaryNode* prev = nullptr;
        
        while (current != nullptr && current->word != word) {
            prev = current;
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "ERROR: Word not found!" << endl;
            return;
        }
        
        prev->next = current->next;
        delete current;
        cout << "key " << word << " deleted successfully!" << endl;
    }
    
    void Print_Dictionary() {
        bool isEmpty = true;
        
        for (int i = 0; i < capacity; i++) {
            DictionaryNode* current = table[i];
            
            if (current != nullptr) {
                isEmpty = false;
                cout << "index " << i << ": ";
                
                while (current != nullptr) {
                    cout << "(" << current->word << ", " << current->meaning << ")";
                    if (current->next != nullptr) {
                        cout << " -> ";
                    }
                    current = current->next;
                }
                cout << endl;
            }
        }
        
        if (isEmpty) {
            cout << "Dictionary is empty!" << endl;
        }
    }
    
    ~Dictionary() {
        for (int i = 0; i < capacity; i++) {
            DictionaryNode* current = table[i];
            while (current != nullptr) {
                DictionaryNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main() {
    Dictionary dict;
    
    dict.AddRecord("AB", "FASTNU");
    dict.AddRecord("CD", "CS");
    dict.AddRecord("EF", "Engineering");
    
    cout << "Dictionary after adding records:" << endl;
    dict.Print_Dictionary();
    cout << endl;
    
    cout << "Search key AB: " << dict.WordSearch("AB") << endl;
    cout << endl;
    
    dict.DeleteWord("EF");
    cout << endl;
    
    cout << "Updated Dictionary:" << endl;
    dict.Print_Dictionary();
    
    return 0;
}