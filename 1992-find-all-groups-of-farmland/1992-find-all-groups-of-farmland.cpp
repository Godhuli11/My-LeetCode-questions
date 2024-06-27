class Solution {
public:
    void dfs(vector<vector<int>>& land , int i , int j , int& mr , int &mc , vector<pair<int,int>> directions , int n , int m){
        land[i][j]=0;
        
        mr = max(mr,i);
        mc = max(mc,j);
        
        for(auto dir : directions){
            int i_ = i + dir.first;
            int j_ = j + dir.second;
            
            if(i_ >= 0 && i_<n && j_>=0 && j_<m && land[i_][j_] == 1 ){
                dfs(land,i_,j_,mr,mc,directions,n,m);
            }
        }
        
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        
        vector<vector<int>> ans ;
        
        
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(land[i][j] == 1){
                    int mr = -1;
                    int mc = -1;
                    
                    dfs(land,i,j,mr,mc,directions,n,m);
                    ans.push_back({i,j,mr,mc});
                }
            }
        }
        
        return ans;
    }
};