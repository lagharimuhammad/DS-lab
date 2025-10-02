#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int d): data(d), next(NULL){}
};

int tailTransverse(Node* temp, int count = 0)
{
	if(temp == NULL)
	{
		return count;
	}
	return tailTransverse(temp->next, count+1);
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
	
	printList(head);
	
	Node* t = head;
	int cnt = tailTransverse(t);
	cout << "Total nodes: " << cnt;
}