#include <iostream>
#include <climits>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;
    
    int minDistance(int dist[], bool visited[]) {
        int min = INT_MAX, min_index;
        
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        
        return min_index;
    }
    
    void printPath(int parent[], int j) {
        if (parent[j] == -1) {
            cout << (char)('A' + j);
            return;
        }
        
        printPath(parent, parent[j]);
        cout << " -> " << (char)('A' + j);
    }
    
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
    }
    
    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }
    
    void dijkstra(int start, int end) {
        int* dist = new int[vertices];
        bool* visited = new bool[vertices];
        int* parent = new int[vertices];
        
        for (int i = 0; i < vertices; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }
        
        dist[start] = 0;
        
        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;
            
            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX && 
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
        
        cout << "Shortest path from " << (char)('A' + start) << " to " << (char)('A' + end) << ":" << endl;
        cout << "Path: ";
        printPath(parent, end);
        cout << endl;
        cout << "Total distance: " << dist[end] << endl;
        
        cout << "\nDistance to all vertices from " << (char)('A' + start) << ":" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << (char)('A' + i) << ": " << dist[i];
            if (i == end) cout << " *";
            cout << endl;
        }
        
        delete[] dist;
        delete[] visited;
        delete[] parent;
    }
    
    void displayGraph() {
        cout << "Graph edges with weights:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = i + 1; j < vertices; j++) {
                if (adjMatrix[i][j] > 0) {
                    cout << (char)('A' + i) << " - " << (char)('A' + j) 
                         << " : " << adjMatrix[i][j] << endl;
                }
            }
        }
    }
    
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    Graph g(5);
    
    int A = 0, B = 1, C = 2, D = 3, E = 4;
    
    g.addEdge(A, B, 4);
    g.addEdge(A, C, 8);
    g.addEdge(B, D, 9);
    g.addEdge(B, C, 6);
    g.addEdge(C, D, 4);
    g.addEdge(C, E, 8);
    g.addEdge(D, E, 6);
    
    g.displayGraph();
    cout << endl;
    
    g.dijkstra(B, E);
    
    return 0;
}