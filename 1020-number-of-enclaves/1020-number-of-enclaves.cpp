class Solution {
public:
    void dfs(vector<vector<int>>& grid , int r , int c , int m , int n)
    {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c]==0){
            return;
        }
        
        grid[r][c] = 0;
        
        dfs(grid,r-1,c,m,n);
        dfs(grid,r+1,c,m,n);
        dfs(grid,r,c-1,m,n);
        dfs(grid,r,c+1,m,n);
        
        
    }    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int row = 0 ; row < m ; row++){
            
            if(grid[row][0]==1){
                dfs(grid,row,0,m,n);
            }
        }
        for(int row = 0 ; row < m ; row++){
            
            if(grid[row][n-1]==1){
                dfs(grid,row,n-1,m,n);
            }
        }
        
        for(int col = 0 ; col <  n; col++){
            
            if(grid[0][col]==1){
                dfs(grid,0,col,m,n);
            }
        }
        for(int col = 0 ; col < n ; col++){
            
            if(grid[m-1][col]==1){
                dfs(grid,m-1,col,m,n);
            }
        }
        
        int cnt = 0;
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};