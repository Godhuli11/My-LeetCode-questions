class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& grid , int n , int m ){
        
        if(i>=n || i<0 || j<0 || j>=m || grid[i][j]==0 ){
            
            return 0;
        } 
        int gold = grid[i][j];
        grid[i][j]=0;
        
        int up =  solve(i-1,j,grid,n,m);
        int down =  solve(i+1,j,grid,n,m);
        int left =  solve(i,j-1,grid,n,m);
        int right =  solve(i,j+1,grid,n,m);
        
        grid[i][j] = gold;
        
        return gold + max(up,max(down,max(left,right)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxGold = 0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]!=0){
                    maxGold = max(maxGold,solve(i,j,grid,n,m));
                }
            }
        }
        
        return maxGold;
    }
};