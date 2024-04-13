class Solution {
public:
    pair<int,int> getCoord(int x , int n){
        int row = n-1 - (x-1)/n;
        
        int col = (x-1)%n;
        
        if((n%2 == 0 && row%2 == 0) || (n%2 == 1 && row%2 == 1)){
            col = n-1-col ; 
        }
        
        return make_pair(row,col);
        
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;
        queue<int> que;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        visited[n-1][0] = true;
        
        que.push(1);
        
        while(!que.empty()){
            
            int N = que.size();
            
            while(N--){
                int x = que.front();
                que.pop();
                
                if(x == n*n){
                    return steps;
                }
                
                for(int i=1 ; i<=6 ; i++){
                    
                    if(x+i > n*n){
                        break;
                    }
                    
                    pair<int,int> coord = getCoord(x+i,n);
                    int r = coord.first;
                    int c = coord.second;
                    
                    if(visited[r][c]==true){
                        continue;
                    }
                    
                    visited[r][c] = true;
                    if(board[r][c]==-1){
                        que.push(i+x);
                    }else{
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};