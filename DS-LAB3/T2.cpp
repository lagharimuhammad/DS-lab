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

void listRotation(Node*& head, int k, int length)
{
	if(head == NULL && k >= length && k <= 0)
	{
		return;
	}
	
	Node* temp = head;
	for(int i = 1; i < k && temp != NULL; i++)
	{
		temp = temp->next;
	}
	
	Node* nayaHead = temp->next;
	temp->next = NULL;
	
	Node* tail = nayaHead;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = head;
	head = nayaHead;
}

int main()
{
	int arr[] = {10, 20, 30, 40 ,50, 60, 70};
	
	Node* head = NULL;
	Node* tail = NULL;
	for (int i = 0; i < 7; i++) 
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
    
    cout << "List: " << endl;
    printList(head);
    
    int move;
    cout << "How many elements: ";
    cin >> move;
    
    listRotation(head, move, 7);
    
    cout << "New list: " << endl;
    printList(head);
}