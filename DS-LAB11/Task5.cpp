#include <iostream>
#include <string>
using namespace std;

class StudentHashTable {
    struct Student {
        int roll;
        string name;
        bool occupied;
    };
    Student table[15];

public:
    StudentHashTable() {
        for (int i = 0; i < 15; i++) {
            table[i].occupied = false;
        }
    }

    void InsertRecord(int roll, string name) {
        int index = roll % 15;
        int attempt = 0;
        while (attempt < 15) {
            int pos = (index + attempt * attempt) % 15;
            if (!table[pos].occupied) {
                table[pos].roll = roll;
                table[pos].name = name;
                table[pos].occupied = true;
                return;
            }
            attempt++;
        }
    }

    void SearchRecord(int roll) {
        int index = roll % 15;
        int attempt = 0;
        while (attempt < 15) {
            int pos = (index + attempt * attempt) % 15;
            if (table[pos].occupied && table[pos].roll == roll) {
                cout << table[pos].name << endl;
                return;
            }
            if (!table[pos].occupied) break;
            attempt++;
        }
        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable ht;
    ht.InsertRecord(101, "Ali");
    ht.InsertRecord(116, "Sara");
    ht.InsertRecord(130, "Zain");

    ht.SearchRecord(101);
    ht.SearchRecord(130);
    ht.SearchRecord(200);

    return 0;
}
