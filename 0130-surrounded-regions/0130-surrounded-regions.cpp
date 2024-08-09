class Solution {
public:
    void dfs( int i , int j ,vector<vector<char>>& b , int m , int n , vector<vector<int>> &vis){
        vis[i][j]=1;
        
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        
        for(int k=0 ; k<4 ; k++){
            int new_i = i + dir[k][0];
            int new_j = j + dir[k][1];
            
            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && vis[new_i][new_j] != 1 && b[new_i][new_j] == 'O'){
                dfs(new_i , new_j , b , m , n , vis);
            }
        }
            
    }
    void solve(vector<vector<char>>& b) {
        
        int m = b.size();
        int n = b[0].size();
        
        vector<vector<int>> vis(m , vector<int>(n,0));
        
        //for rows
        for(int j=0 ; j<n ; j++){
            
            if(b[0][j] == 'O' && vis[0][j] != 1){
                dfs(0,j,b,m,n,vis);
            }
            if(b[m-1][j] == 'O' && vis[m-1][j] != 1){
                dfs(m-1,j,b,m,n,vis);
            }
            
        }
        
        //for cols
        for(int i=0 ; i<m ; i++){
            
            if(b[i][0] == 'O' && vis[i][0] != 1){
                dfs(i,0,b,m,n,vis);
            }
            if(b[i][n-1] == 'O' && vis[i][n-1] != 1){
                dfs(i,n-1,b,m,n,vis);
            }
            
        }
        
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                
                if(vis[i][j] != 1 && b[i][j]=='O'){
                    b[i][j] = 'X';
                }
            }
        }
        
    }
};