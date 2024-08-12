class Solution {
public:
    bool checkCycle(int node , vector<vector<int>>& graph , vector<int>& vis ,vector<int>&inRecursion ){
        vis[node]=1;
        inRecursion[node]=1;
        
        for(auto neigh : graph[node]){
            if(vis[neigh]!=1 && checkCycle(neigh , graph , vis , inRecursion)){
                return true;
            }else if(inRecursion[neigh]==1){
                return true;
            }
        }
        
        inRecursion[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> vis(n,0);
        vector<int> inRecursion(n,0);
        
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                checkCycle(i , graph , vis , inRecursion);
            }
        }
        
        vector<int> safe;
        
        for(int i = 0 ; i<n ; i++){
            if(inRecursion[i]!=1){
                safe.push_back(i);
            }
        }
        
        return safe;
    }
};