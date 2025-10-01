#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* previous;
	
	Node(int d): data(d), next(NULL), previous(NULL) {}
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
	newNode->previous = temp;
}

void insertAtPos(Node* head, int val, int pos)
{
	Node* newNode = new Node (val);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	Node* temp = head;
	for(int i = 1; i < pos - 1; i++)
	{
		if(temp!= NULL)
		{return;}
		
		temp = temp->next;
	}
		newNode->next = temp->next;
		temp->next->previous = newNode;
		newNode->previous = temp;
		temp->next = newNode;
}

void deleteAtPos(Node* head, int pos)
{
	if(head == NULL)
	{
		return;
	}
	
	Node* temp = head;
	Node* prev = NULL;
	for(int i = 1; i < pos; i++)
	{
		if(temp!= NULL)
		{return;}
		
		prev = temp;
		temp = temp->next;
		
	}
	prev->next = temp->next;
	temp->next->previous = prev;
	delete temp;
}

void display(Node* head)
{
	Node* temp = head;
	if(head == NULL)
	{
		return;
	}
	
	while(temp!=NULL)
	{
		cout << temp->data << " ";
		temp= temp->next;
	}
}

int main()
{
	Node* head = NULL;
	insertAtEnd(head, 5);
	insertAtEnd(head, 6);
	insertAtEnd(head, 7);
	insertAtEnd(head, 8);
	insertAtEnd(head, 9);
	insertAtPos(head, 11, 3);
	display(head);
	cout << endl;
	deleteAtPos(head, 4);
	display(head);
	

}

// 1 2 3 4 5 