#include <iostream>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;

const int MAX_VERTICES = 1000; // Adjust this as needed

// Adjacency list to store (node, weight) pairs
vector<pair<int, int>> adj[MAX_VERTICES];

// Function to add an edge to the graph
void addEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight)); // Since the graph is undirected
}


int findMin(vector<int>& key,vector<bool>& mst){
    int min=INT_MAX;
    int min_index;
    for(int i=0; i<key.size(); i++){
        if(key[i]<min && !mst[i]){
            min=key[i];
            min_index=i;
        }
    
    } 
    return min_index;
}

// Function to find the Minimum Spanning Tree using Prim's algorithm
void primsAlgorithm(int src, int V) {
    vector<int> key(V,INT_MAX);
    vector<bool> mst(V,false);
    vector<int> parent(V);
    
    key[src]=0;
    
    
    for(int i=0; i<V-1; i++){
        int min_index=findMin(key,mst);
        mst[min_index]=true;
        
        for(auto it: adj[min_index]){
            if(key[it.first]>it.second && mst[it.first]==false){
                key[it.first]=it.second;
                parent[it.first]=min_index;
            }
        }
    }
    
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}

int main() {
    int V = 5; // Number of vertices

    // Adding edges to the graph
    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 4, 5);
    addEdge(1, 2, 3);
    addEdge(2, 1, 3);
    addEdge(2, 4, 7);
    addEdge(3, 0, 6);
    addEdge(3, 1, 8);
    addEdge(4, 1, 5);
    addEdge(4, 2, 7);

    int src = 0; // Starting node for Prim's algorithm
    cout << "Minimum Spanning Tree starting from node " << src << ":\n";
    primsAlgorithm(src, V);

    return 0;
}
