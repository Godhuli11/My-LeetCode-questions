//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsCheck(int node, vector<int>& visited,vector<int> adj[] ,vector<int>&  dfsPathVis){
         visited[node]=1;
         dfsPathVis[node]=1;
         for(auto adjNode : adj[node]){
             if(visited[adjNode]!=1){
                 if(dfsCheck(adjNode,visited,adj,dfsPathVis)==true){
                     return true;
                 }
             }else if(dfsPathVis[adjNode]==1){
                 return true;
             }
         }
         dfsPathVis[node]=0;
         return false;
         
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> dfsPathVis(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]!=1){
                if(dfsCheck(i,visited,adj,dfsPathVis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends