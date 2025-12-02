#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;
    
    struct Node {
        int vertex;
        Node* next;
        Node(int v) {
            vertex = v;
            next = nullptr;
        }
    };
    
    Node** adjList;
    
    class Queue {
    private:
        struct QueueNode {
            int data;
            QueueNode* next;
            QueueNode(int d) {
                data = d;
                next = nullptr;
            }
        };
        
        QueueNode* front;
        QueueNode* rear;
        
    public:
        Queue() {
            front = rear = nullptr;
        }
        
        void enqueue(int value) {
            QueueNode* newNode = new QueueNode(value);
            if (rear == nullptr) {
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }
        
        int dequeue() {
            if (front == nullptr) {
                return -1;
            }
            QueueNode* temp = front;
            int value = temp->data;
            front = front->next;
            
            if (front == nullptr) {
                rear = nullptr;
            }
            
            delete temp;
            return value;
        }
        
        bool isEmpty() {
            return front == nullptr;
        }
    };
    
    class Stack {
    private:
        struct StackNode {
            int data;
            StackNode* next;
            StackNode(int d) {
                data = d;
                next = nullptr;
            }
        };
        
        StackNode* top;
        
    public:
        Stack() {
            top = nullptr;
        }
        
        void push(int value) {
            StackNode* newNode = new StackNode(value);
            newNode->next = top;
            top = newNode;
        }
        
        int pop() {
            if (top == nullptr) {
                return -1;
            }
            StackNode* temp = top;
            int value = temp->data;
            top = top->next;
            delete temp;
            return value;
        }
        
        bool isEmpty() {
            return top == nullptr;
        }
    };
    
public:
    Graph(int v) {
        vertices = v;
        
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
        
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = nullptr;
        }
    }
    
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        
        Node* newNode = new Node(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;
        
        newNode = new Node(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }
    
    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void displayAdjacencyList() {
        cout << "\nAdjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            Node* current = adjList[i];
            while (current != nullptr) {
                cout << current->vertex << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
    
    void BFS(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
        
        Queue q;
        visited[startVertex] = true;
        q.enqueue(startVertex);
        
        cout << "BFS Traversal: ";
        
        while (!q.isEmpty()) {
            int current = q.dequeue();
            cout << current << " ";
            
            Node* temp = adjList[current];
            while (temp != nullptr) {
                int adjVertex = temp->vertex;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.enqueue(adjVertex);
                }
                temp = temp->next;
            }
        }
        
        cout << endl;
        delete[] visited;
    }
    
    void DFS(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
        
        Stack s;
        s.push(startVertex);
        
        cout << "DFS Traversal: ";
        
        while (!s.isEmpty()) {
            int current = s.pop();
            
            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }
            
            Node* temp = adjList[current];
            while (temp != nullptr) {
                if (!visited[temp->vertex]) {
                    s.push(temp->vertex);
                }
                temp = temp->next;
            }
        }
        
        cout << endl;
        delete[] visited;
    }
    
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
            
            Node* current = adjList[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjMatrix;
        delete[] adjList;
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    
    g.displayAdjacencyMatrix();
    g.displayAdjacencyList();
    
    cout << "\nGraph Traversals starting from vertex 0:" << endl;
    g.BFS(0);
    g.DFS(0);
    
    return 0;
}