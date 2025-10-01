#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int d): data(d), next(NULL) {}
};

void insertAtEnd(Node* &head, int val)
{
	Node* newNode = new Node (val);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	
	Node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void displayReverse(Node* temp)
{
	if(temp == NULL) return;
	displayReverse(temp->next);
	cout << temp->data << endl;
}

int main()
{
	Node* head = NULL;
	insertAtEnd(head, 5);
	insertAtEnd(head, 6);
	insertAtEnd(head, 7);
	insertAtEnd(head, 8);
	insertAtEnd(head, 9);
	Node* temp = head;
	displayReverse(temp);
}