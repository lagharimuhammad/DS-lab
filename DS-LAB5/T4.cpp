#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int d): data(d), next(NULL){}
};

bool nonTailTransverse(Node* temp, int key)
{
	if(temp == NULL)
	{
		return false;
	}
	if(temp->data == key)
	{
		return true;
	}
	bool flag = nonTailTransverse(temp->next, key);
	return flag;
}

void addNode(Node* &head, int val)
{
	Node* newNode = new Node(val);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	
	Node* temp = head;
	while(temp->next != NULL)
	{
		temp= temp->next;
	}
	temp->next = newNode;
}

void printList(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int main()
{
	Node* head = NULL;
	
	addNode(head,5);
	addNode(head, 11);
	addNode(head,7);
	addNode(head,9);
	addNode(head,20);
	addNode(head,6);
	
	
	int key;
	cout << "Enter key to search: ";
	cin >> key;
	
	if(nonTailTransverse(head, key))
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
	
	printList(head);
}