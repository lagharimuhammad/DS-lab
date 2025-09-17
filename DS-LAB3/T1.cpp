#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val): data(val), next(NULL) {}
};

void printList(Node* head)
{
	Node* t = head;
	while(t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

void insertFront(Node*& head, int d)
{
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
}

void insertEnd(Node*& head, int d)
{
	Node* newNode = new Node(d);
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

void insertPos(Node*& head, int d, int index)
{
	if(index == 1)
	{
		insertFront(head,d);
		return;
	}
	Node* temp = head;
	Node* newNode = new Node(d);
	for(int i = 0; i < index; i++)
	{
		if(temp == NULL)
		{
			cout << "Index number not available";
			return;
		}
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteNode(Node*& head, int d)
{
	if(head == NULL)
	{
		return;
	}
	
	Node* temp = head;
	while(temp != NULL && temp->next->data != d)
	{
		temp = temp->next;
	}
	
	Node* deleteNode = temp->next;
	temp->next = deleteNode->next;
	delete deleteNode;
}

int main()
{
	int arr[5] = {3,1,2,5,8};
	cout << "Array: " << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < 5; i++) 
	{
        Node* newNode = new Node(arr[i]);
        if (head == NULL) 
		{
            head = newNode;
            tail = newNode;
        } 
		else 
		{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    cout << "Linked List: " << endl;
	printList(head);
    
    cout << "Final Linked List: " << endl;
    insertEnd(head, 9);
    insertPos(head,11,3);
    insertFront(head,4);
    deleteNode(head,1);
    deleteNode(head,2);
    deleteNode(head,5);
    
    printList(head);
}