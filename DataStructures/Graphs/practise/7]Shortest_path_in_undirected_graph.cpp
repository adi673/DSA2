#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_VERTICES = 1000; // Adjust this as needed

vector<int> adj[MAX_VERTICES]; // Adjacency list for the graph

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Since the graph is undirected
}

// Function to find the shortest path (to be implemented by you)
void shortestPath(int src, int V, int desti) {
    // Add your shortest path finding logic here
    vector<int> parent(V, -1);
    vector<int> vis(V, 0);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            
            if(!vis[it]){
                vis[it]=1;
                parent[it]=node;
                q.push(it);
            }
        }
    }

    int temp=desti;
    while(temp!=-1){
        cout<<temp<<" ";
        temp=parent[temp];
    
    }
    
}

int main() {
   int V = 5; // Number of vertices

    // Adding edges to the graph
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    int src = 0; // Source node
    int desti = 3; // Destination node
    cout << "Shortest paths from source node " << src << ":\n";
    shortestPath(src, V, desti);
    return 0;
}
