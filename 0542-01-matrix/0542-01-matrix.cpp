// class Solution {
// public:
//     bool isValid(int row , int col , int n , int m , vector<vector<int>>& mat){
//         if(row >= 0 && row < n && col >= 0 && col < m && mat[row][col]==1){
//             return true;
//         }
//         return false;
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
//         int n = mat.size();
//         int m = mat[0].size();
        
//         vector<vector<int>> ans(n,vector<int> (m,-1));
        
//         queue<pair<int,int>> q;
        
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<m ; j++){
//                 if(mat[i][j]==0){
//                     ans[i][j]=0;
//                     q.push({i,j});
//                 }
//             }
//         }
        
//         while(!q.empty()){
//             int x = q.front().first;
//             int y = q.front().second;
            
//             q.pop();
            
//             vector<int> dx = {0,0,1,-1};
//             vector<int> dy = {1,-1,0,0};
            
//             for(int i=0 ; i<4 ; i++){
//                 int new_x = x + dx[i];
//                 int new_y = y + dy[i];
                
//                 if(isValid( new_x ,  new_y ,  n ,  m ,  mat)){
//                     ans[new_x][new_y]=1+ans[x][y];
//                     q.push({new_x,new_y});
//                 }
//             }        
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    int m, n;
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        queue<P> que;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        
        auto isSafe = [](int& i, int& j, int& m, int& n) {
            return i>=0 && i<m && j>=0 && j<n;
        };
        
        while(!que.empty()) {
            P p = que.front();
            que.pop();
            
            for(auto &dir : directions) {
                int i = p.first  + dir[0];
                int j = p.second + dir[1];
                
                if(isSafe(i, j, m, n)) {
                    if(dist[i][j] == -1) {
                        que.push({i, j});
                        dist[i][j] = 1 + dist[p.first][p.second];
                    }
                }
            }
            
        }
        
        return dist;
        
    }
};
