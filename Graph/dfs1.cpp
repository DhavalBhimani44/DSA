#include <iostream>
#include <vector>
#include <stack>
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

    void DFS(int startVertex) {
        vector<bool> visited(V, false); 
        stack<int> st; 

        visited[startVertex] = true;
        st.push(startVertex);

        while (!st.empty()) {
            int currentVertex = st.top();
            st.pop();
            cout << currentVertex << " ";
            

            for (int adjacentVertex : l[currentVertex]) { 
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    st.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    cout << "DFS Traversal starting from vertex 0: ";
    graph.DFS(0);

    return 0;
}
