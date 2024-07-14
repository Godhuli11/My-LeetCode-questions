class Solution {
public:
    void dfs(int i ,vector<vector<int>>& adj , vector<int>& vis){
        
        vis[i] = 1;
        
        for(auto neigh : adj[i]){
            if(vis[neigh] != 1){
            dfs(neigh , adj , vis);
            }
        }
     
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int size = connections.size();
        
        vector<vector<int>> adj(n);
        
        vector<int> vis(n,0);
       
        
        for(auto& connection : connections){
             int u = connection[0];
             int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if(size < n-1) return -1;
        
        int connectedComponents = 0;
        
        
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                connectedComponents++;
                dfs(i , adj , vis);
            }
        }
        
        
        return connectedComponents-1;
       
    }
};

