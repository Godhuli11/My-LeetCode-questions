class Solution {
public:
    void dfs( vector<vector<int>>& adj , int node , vector<int>& vis){
        vis[node] = 1;
        
        for(auto neigh : adj[node]){
            if(vis[neigh] != 1){
                dfs(adj , neigh , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
         int n = isConnected.size();
        
         vector<vector<int>> adj(n);
        
         for(int i=0 ; i<n ; i++){
             for(int j=0 ; j<n ; j++){
                 
                 if(isConnected[i][j]==1 && i!=j){
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                 }
             }
         }
        
        vector<int> vis(n , 0);
        
        int cnt=0;
        
        for(int i=0 ; i<n ; i++){
            if(vis[i]==0){
                cnt++;
                dfs(adj , i , vis);
            }
        }
        
        return cnt;
    }
};