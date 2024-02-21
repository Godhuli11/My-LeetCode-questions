class Solution {
public:
    int dfs( vector<vector<int>>& adj, int curr , int p , vector<bool>& hasApple) {
       int time = 0;
        
        for(int &child : adj[curr]){
            if(child == p) continue;
            
            int total_time_from_my_child = dfs(adj,child,curr,hasApple);
            
            if(total_time_from_my_child >0 || hasApple[child]){
                time += total_time_from_my_child + 2 ;
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       
        vector<vector<int>> adj(n);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

       return dfs( adj,0,-1, hasApple);

      
    }
};


    