#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void deleteNode(int nodeToDelete) {
        for (int i = 0; i < V; i++) {
            l[i].remove(nodeToDelete);
        }
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (int nbr : l[i]) {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int x, y;
        cout << "Enter edge " << i + 1 << " (format: source destination): ";
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << "Adjacency List of the Graph:" << endl;
    g.printAdjList();

    int nodeToDelete;
    cout << "Enter the node you want to delete: ";
    cin >> nodeToDelete;
    g.deleteNode(nodeToDelete);
    cout << "Adjacency list after deleting " << nodeToDelete << " : " << endl;
    g.printAdjList();

    return 0;
}
