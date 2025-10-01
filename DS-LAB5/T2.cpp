#include <iostream>
#include <string>
using namespace std;

class Student{
    int rollNo;
    string name;
public:
    Student(){}
    Student(int roll, string n){
        rollNo = roll;
        name = n;
    }
    void displayDetails(){
        cout<<name<<" "<<rollNo;
    }
    
};

struct Node{
    Student std;
    Node* next;
    Node(Student std) {
        this->std = std;
        this->next = NULL;
    }
};
Node* insertAtEnd(Node* head, Student std) {
    Node* newNode = new Node(std);

    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}
//print function
void printList(Node* head) {
    Node* temp = head;
    while (temp->next!= nullptr) {
        temp->std.displayDetails();
        cout<<" -> " << endl;
        temp = temp->next;
    }
    temp->std.displayDetails();
    cout<<endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head, Student(1, "Baqar"));
    head = insertAtEnd(head, Student(2, "Baqar senior"));
    head = insertAtEnd(head, Student(3, "Baqar Junior"));

    printList(head);

    return 0;
}